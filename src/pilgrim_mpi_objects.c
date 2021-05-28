/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "pilgrim_mpi_objects.h"
#include "pilgrim_utils.h"

#define MPI_OBJ_DEFINE(Type)                \
    ObjHash_##Type *hash_##Type = NULL;     \
    ObjNode_##Type *list_##Type = NULL;     \
                                            \
    static int allocated_##Type;            \
    static int invalid_##Type = -1;         \
                                            \
    ObjHash_##Type* get_hash_entry_##Type(const Type *obj) {            \
        if(obj == NULL)                                                 \
            return NULL;                                                \
        ObjHash_##Type *entry = NULL;                                   \
        HASH_FIND(hh, hash_##Type, obj, sizeof(Type), entry);           \
        return entry;                                                   \
    }                                                                   \
                                                                        \
    int get_object_id_##Type(const Type *obj) {                        \
        if(obj == NULL)                                                 \
            return invalid_##Type;                                     \
        ObjHash_##Type *entry = get_hash_entry_##Type(obj);             \
        /* if not exists in the hash table, then this should be the     \
         first time the object is created, need to add it to the        \
         hash table */                                                  \
        if(entry == NULL) {                                             \
            entry = pilgrim_malloc(sizeof(ObjHash_##Type));                   \
            entry->key = pilgrim_malloc(sizeof(Type));                        \
            memcpy(entry->key, obj, sizeof(Type));                      \
            entry->id_node = list_##Type;                               \
            /* get a free id from the head of the free list             \
               if the head is NULL, which means we have no free ids,    \
               then create one according to the allocated counter */    \
            if(entry->id_node == NULL) {                                \
                entry->id_node = pilgrim_malloc(sizeof(ObjNode_##Type));      \
                entry->id_node->id = allocated_##Type ++;               \
            } else {                                                    \
                DL_DELETE(list_##Type, entry->id_node);                 \
            }                                                           \
            HASH_ADD_KEYPTR(hh, hash_##Type, entry->key, sizeof(Type), entry); \
        }                                                               \
        return entry->id_node->id;                                      \
    }                                                                   \
                                                                        \
    void object_release_##Type(const Type *obj) {                       \
        ObjHash_##Type *entry = get_hash_entry_##Type(obj);             \
        if(entry) {                                                     \
            /* add the id back to the free list */                      \
            DL_APPEND(list_##Type, entry->id_node);                     \
            HASH_DEL(hash_##Type, entry);                               \
            pilgrim_free(entry->key, sizeof(Type));                     \
            pilgrim_free(entry, sizeof(ObjHash_##Type));                \
        }                                                               \
    }                                                                   \
                                                                        \
    void object_cleanup_##Type() {                                      \
        ObjHash_##Type *entry, *tmp;                                    \
        HASH_ITER(hh, hash_##Type, entry, tmp) {                        \
            HASH_DEL(hash_##Type, entry);                               \
            pilgrim_free(entry->key, sizeof(Type));                     \
            pilgrim_free(entry->id_node, sizeof(ObjNode_##Type));       \
            pilgrim_free(entry, sizeof(ObjHash_##Type));                \
        }                                                               \
                                                                        \
        ObjNode_##Type *node, *tmp2;                                    \
        DL_FOREACH_SAFE(list_##Type, node, tmp2) {                      \
            DL_DELETE(list_##Type, node);                               \
            pilgrim_free(node, sizeof(ObjNode_##Type));                 \
        }                                                               \
    }


MPI_OBJ_DEFINE(MPI_Datatype);
MPI_OBJ_DEFINE(MPI_Info);
MPI_OBJ_DEFINE(MPI_File);
MPI_OBJ_DEFINE(MPI_Win);
MPI_OBJ_DEFINE(MPI_Group);
MPI_OBJ_DEFINE(MPI_Op);
MPI_OBJ_DEFINE(MPI_Message);


/*
 * ======================================================================
 *                          MPI_Request
 * ======================================================================
 *
 */
RequestHash *hash_MPI_Request;
RequestNode *list_MPI_Request;
RequestNodeHash *request_free_ids;

static int invalid_request_id = -1;
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

int request2id(MPI_Request *req, int source, int tag) {
    if(req==NULL || *req == MPI_REQUEST_NULL)
        return invalid_request_id;

    RequestHash *entry = request_hash_entry(req);
    if(entry == NULL) {
        entry = pilgrim_malloc(sizeof(RequestHash));
        entry->key = pilgrim_malloc(sizeof(MPI_Request));
        memcpy(entry->key, req, sizeof(MPI_Request));
        entry->key_len = sizeof(MPI_Request);
        entry->req_node = list_MPI_Request;               // get the first (head) free id
        entry->any_source = (source == MPI_ANY_SOURCE);
        entry->any_tag = (tag == MPI_ANY_TAG);

        entry->signature = NULL;
        entry->signature_len = 0;

        if(entry->req_node == NULL) {                       // free list is empty, create one according to allocated_request_id
            entry->req_node = (RequestNode*) pilgrim_malloc(sizeof(RequestNode));
            entry->req_node->id = allocated_request_id++;
        } else {                                            // free list is not empty, get the first one and remove it from list
            DL_DELETE(list_MPI_Request, entry->req_node);
        }

        HASH_ADD_KEYPTR(hh, hash_MPI_Request, entry->key, entry->key_len, entry);
    }
    return entry->req_node->id;
}

int get_object_id_MPI_Request(MPI_Request *req) {
    RequestHash *entry = request_hash_entry(req);
    if(!entry)
        return request2id(req, 0, 0);

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
MPICommHash *hash_MPI_Comm = NULL;


static int invalid_comm_id = -999;
static int comm_null_id = -1;
static int comm_world_id = -2;
static int comm_self_id = -3;
static int allocated_comm_id = 0;
// Pick a unique name for newcomm
int comm2id(MPI_Comm *newcomm) {
    int id = allocated_comm_id++;
    return id;

    /*
     * The below code generates globally unique id.
    void *id = pilgrim_malloc(COMM_ID_LEN);

    int world_rank;
    PMPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    memcpy(id, newcomm, sizeof(MPI_Comm));
    memcpy(id+sizeof(MPI_Comm), &world_rank, sizeof(int));

    return id;
    */
}

void add_mpi_comm_hash_entry(MPI_Comm *newcomm, int id) {
    MPICommHash *entry = pilgrim_malloc(sizeof(MPICommHash));
    entry->key = pilgrim_malloc(sizeof(MPI_Comm));
    memcpy(entry->key, newcomm, sizeof(MPI_Comm));
    entry->id = id;
    HASH_ADD_KEYPTR(hh, hash_MPI_Comm, entry->key, sizeof(MPI_Comm), entry);
}


int generate_intracomm_id(MPI_Comm *newcomm) {
    // check for predefined comm
    if((newcomm == NULL) || (*newcomm==MPI_COMM_NULL))
        return get_predefined_comm_id(MPI_COMM_NULL);

    int id;
    int rank, is_inter;

    // *newcomm might actually be an inter-communicator
    // This is only possible when MPI_Comm_create() is
    // called with an inter-communicator as the input.
    PMPI_Comm_test_inter(*newcomm, &is_inter);

    MPI_Comm intracomm;
    if(!is_inter)
        intracomm = *newcomm;
    else
        PMPI_Intercomm_merge(*newcomm, 0, &intracomm);

    PMPI_Comm_rank(intracomm, &rank);

    if(rank == 0)
        id = comm2id(newcomm);
    PMPI_Bcast(&id, 1, MPI_INT, 0, intracomm);

    if(is_inter)
        PMPI_Comm_free(&intracomm);

    add_mpi_comm_hash_entry(newcomm, id);
    return id;
}

int generate_intercomm_id(MPI_Comm local_comm, MPI_Comm *newcomm, int tag) {
    // check for predefined comm
    if((newcomm == NULL) || (*newcomm== MPI_COMM_NULL))
        return get_predefined_comm_id(MPI_COMM_NULL);

    int local_rank;
    PMPI_Comm_rank(*newcomm, &local_rank);

    int id;

    // Local rank 0 of two communicator exchange a random number
    // to decide who picks the unique name for the new communicator
    if(local_rank == 0) {
        time_t t;
        int sendbuf = 0, recvbuf = 0;
        sendbuf = randint();
        PMPI_Sendrecv(&sendbuf, 1, MPI_INT, 0, tag, &recvbuf, 1, MPI_INT, 0, tag, *newcomm, MPI_STATUS_IGNORE);

        // I will decide the unique id and send it to the other one
        if(sendbuf < recvbuf) {
            id = comm2id(newcomm);
            PMPI_Send(&id, 1, MPI_INT, 0, tag, *newcomm);
        } else if(sendbuf > recvbuf) {
            PMPI_Recv(&id, 1, MPI_INT, 0, tag, *newcomm, MPI_STATUS_IGNORE);
        } else {
            // Very unlikely
            abort();
        }
    } else {
        // all non-rank 0 processes in the two local communicators
    }

    PMPI_Bcast(&id, 1, MPI_INT, 0, local_comm);
    add_mpi_comm_hash_entry(newcomm, id);
    return id;
}

int get_predefined_comm_id(MPI_Comm comm) {
    if(comm == MPI_COMM_NULL)
        return comm_null_id;
    if(comm == MPI_COMM_WORLD)
        return comm_world_id;
    if(comm == MPI_COMM_SELF)
        return comm_self_id;
    return invalid_comm_id;
}

/*
 * Name the following functinos in a way that we can
 * use the above defined MACROs:
 *  - MPI_OBJ_ID(MPI_Comm, comm);
 *  - MPI_OBJ_RELEASE(MPI_Comm, comm);
 */
int get_object_id_MPI_Comm(MPI_Comm *comm) {
    // check for predefined comm
    if((comm == NULL) || (*comm== MPI_COMM_NULL))
        return get_predefined_comm_id(MPI_COMM_NULL);
    else if((*comm == MPI_COMM_WORLD) || (*comm == MPI_COMM_SELF))
        return get_predefined_comm_id(*comm);

    // otherwise, check for hash table
    MPICommHash *entry = NULL;
    HASH_FIND(hh, hash_MPI_Comm, comm, sizeof(MPI_Comm), entry);
    if(entry) {
        return entry->id;
    } else {
        // not possible
        if(!entry)
            printf("Not possible! cannot find MPI_Comm entry\n");
        return invalid_comm_id;
    }
}
void object_release_MPI_Comm(MPI_Comm *comm) {
    if( (comm==NULL) || (*comm==MPI_COMM_NULL) || (*comm==MPI_COMM_SELF) || (*comm == MPI_COMM_WORLD) )
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
