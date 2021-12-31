/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "pilgrim_mpi_objects.h"
#include "pilgrim_consts.h"
#include "pilgrim_utils.h"

#define MPI_OBJ_DEFINE(Type)                                                        \
    ObjHash_##Type *hash_##Type = NULL;                                             \
    ObjNode_##Type *list_##Type = NULL;                                             \
                                                                                    \
    static int allocated_##Type;                                                    \
    static int invalid_##Type = PILGRIM_INVALID_MPI_OBJECT_ID;                      \
                                                                                    \
    ObjHash_##Type* get_hash_entry_##Type(const Type *obj) {                        \
        if(obj == NULL)                                                             \
            return NULL;                                                            \
        ObjHash_##Type *entry = NULL;                                               \
        HASH_FIND(hh, hash_##Type, obj, sizeof(Type), entry);                       \
        return entry;                                                               \
    }                                                                               \
                                                                                    \
    int get_object_id_##Type(const Type *obj) {                                     \
        if(obj == NULL)                                                             \
            return invalid_##Type;                                                  \
        if(strcmp(#Type, "MPI_Datatype")==0) {                                      \
            int id = mpi_datatype_to_symbolic_id(obj);                              \
            /* A buitin datatype like MPI_INT */                                    \
            if(id!=PILGRIM_CUSTOM_MPI_DATATYPE_ID)                                  \
                return id;                                                          \
        }                                                                           \
        if(strcmp(#Type, "MPI_Op")==0) {                                            \
            int id = mpi_op_to_symbolic_id(obj);                                    \
            /* A buitin op like MPI_SUM */                                          \
            if(id!=PILGRIM_CUSTOM_MPI_OP_ID)                                        \
                return id;                                                          \
        }                                                                           \
        if(strcmp(#Type, "MPI_Errhandler")==0) {                                    \
            int id = mpi_errhandler_to_symbolic_id(obj);                            \
            if(id!=PILGRIM_CUSTOM_MPI_ERRHANDLER_ID)                                \
                return id;                                                          \
        }                                                                           \
        ObjHash_##Type *entry = get_hash_entry_##Type(obj);                         \
        /* if not exists in the hash table, then this should be the                 \
         first time the object is created, need to add it to the                    \
         hash table */                                                              \
        if(entry == NULL) {                                                         \
            entry = pilgrim_malloc(sizeof(ObjHash_##Type));                         \
            entry->key = pilgrim_malloc(sizeof(Type));                              \
            memcpy(entry->key, obj, sizeof(Type));                                  \
            entry->id_node = list_##Type;                                           \
            /* get a free id from the head of the free list                         \
               if the head is NULL, which means we have no free ids,                \
               then create one according to the allocated counter */                \
            if(entry->id_node == NULL) {                                            \
                entry->id_node = pilgrim_malloc(sizeof(ObjNode_##Type));            \
                entry->id_node->id = allocated_##Type ++;                           \
            } else {                                                                \
                DL_DELETE(list_##Type, entry->id_node);                             \
            }                                                                       \
            HASH_ADD_KEYPTR(hh, hash_##Type, entry->key, sizeof(Type), entry);      \
        }                                                                           \
        return entry->id_node->id;                                                  \
    }                                                                               \
                                                                                    \
    void object_release_##Type(const Type *obj) {                                   \
        ObjHash_##Type *entry = get_hash_entry_##Type(obj);                         \
        if(entry) {                                                                 \
            /* add the id back to the free list */                                  \
            DL_APPEND(list_##Type, entry->id_node);                                 \
            HASH_DEL(hash_##Type, entry);                                           \
            pilgrim_free(entry->key, sizeof(Type));                                 \
            pilgrim_free(entry, sizeof(ObjHash_##Type));                            \
        }                                                                           \
    }                                                                               \
                                                                                    \
    void object_cleanup_##Type() {                                                  \
        ObjHash_##Type *entry, *tmp;                                                \
        HASH_ITER(hh, hash_##Type, entry, tmp) {                                    \
            HASH_DEL(hash_##Type, entry);                                           \
            pilgrim_free(entry->key, sizeof(Type));                                 \
            pilgrim_free(entry->id_node, sizeof(ObjNode_##Type));                   \
            pilgrim_free(entry, sizeof(ObjHash_##Type));                            \
        }                                                                           \
                                                                                    \
        ObjNode_##Type *node, *tmp2;                                                \
        DL_FOREACH_SAFE(list_##Type, node, tmp2) {                                  \
            DL_DELETE(list_##Type, node);                                           \
            pilgrim_free(node, sizeof(ObjNode_##Type));                             \
        }                                                                           \
    }


MPI_OBJ_DEFINE(MPI_Datatype);
MPI_OBJ_DEFINE(MPI_Info);
MPI_OBJ_DEFINE(MPI_File);
MPI_OBJ_DEFINE(MPI_Win);
MPI_OBJ_DEFINE(MPI_Group);
MPI_OBJ_DEFINE(MPI_Op);
MPI_OBJ_DEFINE(MPI_Message);
MPI_OBJ_DEFINE(MPI_Errhandler);


/*
 * ======================================================================
 *                          MPI_Request
 * ======================================================================
 *
 */
RequestHash *hash_MPI_Request;
RequestNode *list_MPI_Request;
RequestNodeHash *request_free_ids;

static int invalid_request_id = PILGRIM_MPI_REQUEST_NULL;
static int allocated_request_id = 0;

RequestHash* request_hash_entry(MPI_Request *req) {
    if(req==NULL || *req == MPI_REQUEST_NULL)
        return NULL;

    RequestHash *entry = NULL;
    HASH_FIND(hh, hash_MPI_Request, req, sizeof(MPI_Request), entry);
    return entry;
}

/*
int create_request_id(MPI_Request *req, void* signature, int signature_len) {
    if(req==NULL || *req == MPI_REQUEST_NULL)
        return invalid_request_id;
    return invalid_request_id;

    RequestHash* entry = pilgrim_malloc(sizeof(RequestHash));
    entry->key = pilgrim_malloc(sizeof(MPI_Request));
    memcpy(entry->key, req, sizeof(MPI_Request));
    entry->key_len = sizeof(MPI_Request);
    entry->signature = signature;
    entry->signature_len = signature_len;
    //entry->any_source = (source == MPI_ANY_SOURCE);
    //entry->any_tag = (tag == MPI_ANY_TAG);
    HASH_ADD_KEYPTR(hh, hash_MPI_Request, entry->key, entry->key_len, entry);

    RequestNodeHash *ids_pool = NULL;
    HASH_FIND(hh, request_free_ids, signature, signature_len, ids_pool);
    if(ids_pool == NULL) {
        ids_pool = pilgrim_malloc(sizeof(RequestNodeHash));
        ids_pool->key = pilgrim_malloc(signature_len);
        memcpy(ids_pool->key, signature, signature_len);
        ids_pool->key_len = signature_len;
        ids_pool->free_ids = NULL;
        HASH_ADD_KEYPTR(hh, request_free_ids, ids_pool->key, signature_len, ids_pool);
    }

    entry->req_node = ids_pool->free_ids;               // get the first (head) free id
    if(entry->req_node == NULL) {                       // free list is empty, create one according to allocated_request_id
        entry->req_node = (RequestNode*) pilgrim_malloc(sizeof(RequestNode));
        entry->req_node->id = allocated_request_id++;
    } else {                                            // free list is not empty, get the first one and remove it from list
        DL_DELETE(ids_pool->free_ids, entry->req_node);
    }

    return entry->req_node->id;
}
*/

int create_request_id(MPI_Request *req, bool from_universal_pool, int func_id, int src_or_dst, int tag, int comm) {
    if(req==NULL || *req == MPI_REQUEST_NULL)
        return invalid_request_id;

    RequestHash *entry = request_hash_entry(req);
    assert(entry == NULL);

    entry = pilgrim_malloc(sizeof(RequestHash));
    entry->key = pilgrim_malloc(sizeof(MPI_Request));
    memcpy(entry->key, req, sizeof(MPI_Request));
    entry->key_len = sizeof(MPI_Request);
    entry->any_source = (src_or_dst == MPI_ANY_SOURCE);
    entry->any_tag = (tag == MPI_ANY_TAG);


    // request id generated from signature-specific ids pool
    // i.e., isend and irecv functions.
    if(!from_universal_pool) {

        int sig[] = {func_id, src_or_dst, tag, comm};
        entry->signature_len = sizeof(int) * 4;
        entry->signature = pilgrim_malloc(entry->signature_len);
        memcpy(entry->signature, sig, entry->signature_len);

        RequestNodeHash *ids_pool = NULL;
        HASH_FIND(hh, request_free_ids, entry->signature, entry->signature_len, ids_pool);

        if(ids_pool == NULL) {
            ids_pool = pilgrim_malloc(sizeof(RequestNodeHash));
            ids_pool->key_len = entry->signature_len;
            ids_pool->key = pilgrim_malloc(ids_pool->key_len);
            memcpy(ids_pool->key, entry->signature, ids_pool->key_len);
            ids_pool->free_ids = NULL;
            HASH_ADD_KEYPTR(hh, request_free_ids, ids_pool->key, ids_pool->key_len, ids_pool);
        }

        entry->req_node = ids_pool->free_ids;           // get the first (head) free id

        if(entry->req_node == NULL) {                   // free list is empty, create one according to allocated_request_id
            entry->req_node = (RequestNode*) pilgrim_malloc(sizeof(RequestNode));
            entry->req_node->id = allocated_request_id++;
        } else {                                        // free list is not empty, get the first one and remove it from list
            DL_DELETE(ids_pool->free_ids, entry->req_node);
        }

    }
    // request id generated from universal request ids pool
    // i.e., all functions except isend/irecv
    else {
        entry->signature = NULL;
        entry->signature_len = 0;

        entry->req_node = list_MPI_Request;             // get the first (head) free id

        if(entry->req_node == NULL) {                   // free list is empty, create one according to allocated_request_id
            entry->req_node = (RequestNode*) pilgrim_malloc(sizeof(RequestNode));
            entry->req_node->id = allocated_request_id++;
        } else {                                        // free list is not empty, get the first one and remove it from list
            DL_DELETE(list_MPI_Request, entry->req_node);
        }
    }



    HASH_ADD_KEYPTR(hh, hash_MPI_Request, entry->key, entry->key_len, entry);

    return entry->req_node->id;
}

int get_object_id_MPI_Request(MPI_Request *req) {
    RequestHash *entry = request_hash_entry(req);
    if(!entry)
        return create_request_id(req, true, 0, 0, 0, 0);

    if(entry && entry->req_node)
        return entry->req_node->id;
    else
        return invalid_request_id;
}

void object_release_MPI_Request(MPI_Request *req) {
    RequestHash *entry = request_hash_entry(req);
    if(entry) {
        HASH_DEL(hash_MPI_Request, entry);

        RequestNodeHash *ids_pool = NULL;
        HASH_FIND(hh, request_free_ids, entry->signature, entry->signature_len, ids_pool);
        if(entry->req_node) {
            if(ids_pool != NULL)
                DL_APPEND(ids_pool->free_ids, entry->req_node);    // Add the id back to the signature-specific free list
            else
                DL_APPEND(list_MPI_Request, entry->req_node);      // Add the id back to the universal free list
        }

        pilgrim_free(entry->key, entry->key_len);
        pilgrim_free(entry->signature, entry->signature_len);
        pilgrim_free(entry, sizeof(RequestHash));
    }
}

void object_cleanup_MPI_Request() {
    RequestHash *entry, *tmp;
    HASH_ITER(hh, hash_MPI_Request, entry, tmp) {
        HASH_DEL(hash_MPI_Request, entry);
        pilgrim_free(entry->key, entry->key_len);
        pilgrim_free(entry->signature, entry->signature_len);
        pilgrim_free(entry->req_node, sizeof(RequestNode));
        pilgrim_free(entry, sizeof(RequestHash));
    }

    RequestNodeHash *entry2, *tmp2;
    RequestNode *node, *tmp3;

    HASH_ITER(hh, request_free_ids, entry2, tmp2) {
        HASH_DEL(request_free_ids, entry2);

        DL_FOREACH_SAFE(entry2->free_ids, node, tmp3) {
            DL_DELETE(entry2->free_ids, node);
            pilgrim_free(node, sizeof(RequestNode));
        }

        pilgrim_free(entry2->key, entry2->key_len);
        pilgrim_free(entry2, sizeof(RequestNodeHash));
    }

    DL_FOREACH_SAFE(list_MPI_Request, node, tmp3) {
        DL_DELETE(list_MPI_Request, node);
        pilgrim_free(node, sizeof(RequestNode));
    }
}




/*
 * ======================================================================
 *                          MPI_Comm
 * ======================================================================
 *
 */
// TODO now we handles MPI_Comm just like other MPI objects
// Delete below code and use the above macros
MPICommHash *hash_MPI_Comm = NULL;

static int allocated_comm_id = 0;

void add_mpi_comm_hash_entry(MPI_Comm *newcomm, int id) {
    MPICommHash *entry = pilgrim_malloc(sizeof(MPICommHash));
    entry->key = pilgrim_malloc(sizeof(MPI_Comm));
    memcpy(entry->key, newcomm, sizeof(MPI_Comm));
    entry->id = id;
    HASH_ADD_KEYPTR(hh, hash_MPI_Comm, entry->key, sizeof(MPI_Comm), entry);
}

int generate_intracomm_id(MPI_Comm *newcomm) {
    int id = allocated_comm_id++;
    add_mpi_comm_hash_entry(newcomm, id);
}

int generate_intercomm_id(MPI_Comm local_comm, MPI_Comm *newcomm, int tag) {
    int id = allocated_comm_id++;
    add_mpi_comm_hash_entry(newcomm, id);
}

/*
 * Name the following functinos in a way that we can
 * use the above defined MACROs:
 *  - MPI_OBJ_ID(MPI_Comm, comm);
 *  - MPI_OBJ_RELEASE(MPI_Comm, comm);
 */
int get_object_id_MPI_Comm(MPI_Comm *comm) {
    int id = mpi_comm_to_symbolic_id(comm);
    // built in communicator like MPI_COMM_WORLD
    if(id != PILGRIM_CUSTOM_MPI_COMM_ID)
        return id;

    // otherwise, check for hash table
    MPICommHash *entry = NULL;
    HASH_FIND(hh, hash_MPI_Comm, comm, sizeof(MPI_Comm), entry);
    if(entry) {
        return entry->id;
    } else {
        // not possible
        if(!entry)
            printf("Not possible! cannot find MPI_Comm entry\n");
        return PILGRIM_MPI_COMM_NULL_ID;
    }
}
void object_release_MPI_Comm(MPI_Comm *comm) {
    int id = mpi_comm_to_symbolic_id(comm);
    if(id != PILGRIM_CUSTOM_MPI_COMM_ID)
        return;

    MPICommHash *entry = NULL;
    HASH_FIND(hh, hash_MPI_Comm, comm, sizeof(MPI_Comm), entry);
    if(entry) {
        HASH_DEL(hash_MPI_Comm, entry);
        pilgrim_free(entry->key, sizeof(MPI_Comm));
        pilgrim_free(entry, sizeof(MPICommHash));
    }
}

void object_cleanup_MPI_Comm() {
    MPICommHash *entry, *tmp;
    HASH_ITER(hh, hash_MPI_Comm, entry, tmp) {
        HASH_DEL(hash_MPI_Comm, entry);
        pilgrim_free(entry->key, sizeof(MPI_Comm));
        pilgrim_free(entry, sizeof(MPICommHash));
    }
}
