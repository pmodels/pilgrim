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
    int* get_object_id_##Type(const Type *obj) {                        \
        if(obj == NULL)                                                 \
            return &invalid_##Type;                                     \
        ObjHash_##Type *entry = get_hash_entry_##Type(obj);             \
        /* if not exists in the hash table, then this should be the     \
         first time the object is created, need to add it to the        \
         hash table */                                                  \
        if(entry == NULL) {                                             \
            entry = dlmalloc(sizeof(ObjHash_##Type));                   \
            entry->key = dlmalloc(sizeof(Type));                        \
            memcpy(entry->key, obj, sizeof(Type));                      \
            entry->id_node = list_##Type;                               \
            /* get a free id from the head of the free list             \
               if the head is NULL, which means we have no free ids,    \
               then create one according to the allocated counter */    \
            if(entry->id_node == NULL) {                                \
                entry->id_node = dlmalloc(sizeof(ObjNode_##Type));      \
                entry->id_node->id = allocated_##Type ++;               \
            } else {                                                    \
                DL_DELETE(list_##Type, entry->id_node);                 \
            }                                                           \
            HASH_ADD_KEYPTR(hh, hash_##Type, entry->key, sizeof(Type), entry); \
        }                                                               \
        return &(entry->id_node->id);                                   \
    }                                                                   \
                                                                        \
    void object_release_##Type(const Type *obj) {                       \
        ObjHash_##Type *entry = get_hash_entry_##Type(obj);             \
        if(entry) {                                                     \
            /* add the id back to the free list */                      \
            DL_APPEND(list_##Type, entry->id_node);                     \
            HASH_DEL(hash_##Type, entry);                               \
            dlfree(entry->key);                                         \
            dlfree(entry);                                              \
        }                                                               \
    }                                                                   \
                                                                        \
    void object_cleanup_##Type() {                                      \
        ObjHash_##Type *entry, *tmp;                                    \
        HASH_ITER(hh, hash_##Type, entry, tmp) {                        \
            HASH_DEL(hash_##Type, entry);                               \
            dlfree(entry->key);                                         \
            dlfree(entry->id_node);                                     \
            dlfree(entry);                                              \
        }                                                               \
                                                                        \
        ObjNode_##Type *node, *tmp2;                                    \
        DL_FOREACH_SAFE(list_##Type, node, tmp2) {                      \
            DL_DELETE(list_##Type, node);                               \
            dlfree(node);                                               \
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
static int invalid_request_id = -1;
static int allocated_request_id = 0;

RequestHash* request_hash_entry(MPI_Request *req) {
    if(req==NULL || *req == MPI_REQUEST_NULL)
        return NULL;

    RequestHash *entry = NULL;
    HASH_FIND(hh, hash_MPI_Request, req, sizeof(MPI_Request), entry);
    return entry;
}

int* request2id(MPI_Request *req, int source, int tag) {
    if(req==NULL || *req == MPI_REQUEST_NULL) {
        return &invalid_request_id;
    }

    RequestHash *entry = request_hash_entry(req);
    if(entry == NULL) {
        entry = dlmalloc(sizeof(RequestHash));
        entry->key = dlmalloc(sizeof(MPI_Request));
        memcpy(entry->key, req, sizeof(MPI_Request));
        entry->key_len = sizeof(MPI_Request);
        entry->req_node = list_MPI_Request;               // get the first (head) free id
        entry->any_source = (source == MPI_ANY_SOURCE);
        entry->any_tag = (tag == MPI_ANY_TAG);

        if(entry->req_node == NULL) {                       // free list is empty, create one according to allocated_request_id
            entry->req_node = (RequestNode*) dlmalloc(sizeof(RequestNode));
            entry->req_node->id = allocated_request_id++;
        } else {                                            // free list is not empty, get the first one and remove it from list
            DL_DELETE(list_MPI_Request, entry->req_node);
        }

        HASH_ADD_KEYPTR(hh, hash_MPI_Request, entry->key, entry->key_len, entry);
    }
    return &(entry->req_node->id);
}

void free_request(MPI_Request *req) {
    RequestHash *entry = request_hash_entry(req);
    if(entry) {
        DL_APPEND(list_MPI_Request, entry->req_node);    // Add the id back to the free list
        HASH_DEL(hash_MPI_Request, entry);
        dlfree(entry->key);
        dlfree(entry);
    }
}

void object_cleanup_MPI_Request() {
    RequestHash *entry, *tmp;
    HASH_ITER(hh, hash_MPI_Request, entry, tmp) {
        HASH_DEL(hash_MPI_Request, entry);
        dlfree(entry->key);
        dlfree(entry->req_node);
        dlfree(entry);
    }
    RequestNode *node, *tmp2;
    DL_FOREACH_SAFE(list_MPI_Request, node, tmp2) {
        DL_DELETE(list_MPI_Request, node);
        dlfree(node);
    }
}




/*
 * ======================================================================
 *                          MPI_Comm
 * ======================================================================
 *
 */
MPICommHash *hash_MPI_Comm = NULL;
char predefined_comm_id[64];
#define COMM_ID_LEN (sizeof(MPI_Comm)+sizeof(int))

// Pick a unique name for newcomm
void* comm2id(MPI_Comm *newcomm) {
    void *id = dlmalloc(COMM_ID_LEN);

    int world_rank;
    PMPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    memcpy(id, newcomm, sizeof(MPI_Comm));
    memcpy(id+sizeof(MPI_Comm), &world_rank, sizeof(int));

    return id;
}

void add_mpi_comm_hash_entry(MPI_Comm *newcomm, void *id) {
    MPICommHash *entry = dlmalloc(sizeof(MPICommHash));
    entry->key = dlmalloc(sizeof(MPI_Comm));
    memcpy(entry->key, newcomm, sizeof(MPI_Comm));
    entry->id = id;
    HASH_ADD_KEYPTR(hh, hash_MPI_Comm, entry->key, sizeof(MPI_Comm), entry);
}

void* generate_intracomm_id(MPI_Comm *newcomm) {
    int rank;
    PMPI_Comm_rank(*newcomm, &rank);

    void *id;

    if(rank == 0)
        id = comm2id(newcomm);
    else
        id = dlmalloc(COMM_ID_LEN);

    PMPI_Bcast(id, COMM_ID_LEN, MPI_BYTE, 0, *newcomm);
    add_mpi_comm_hash_entry(newcomm, id);
    return id;
}

void* generate_intercomm_id(MPI_Comm local_comm, MPI_Comm *newcomm, int tag) {
    int local_rank, newcomm_rank;
    PMPI_Comm_rank(local_comm, &local_rank);
    PMPI_Comm_rank(*newcomm, &newcomm_rank);

    void *id;

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
            PMPI_Send(id, 1, MPI_INT, 0, tag, *newcomm);
        } else if(sendbuf > recvbuf) {
            id = dlmalloc(COMM_ID_LEN);
            PMPI_Recv(id, 1, MPI_INT, 0, tag, *newcomm, MPI_STATUS_IGNORE);
        } else {
            // Very unlikely
            abort();
        }
    } else {
        // all non-rank 0 processes in the two local communicators
        id = dlmalloc(COMM_ID_LEN);
    }

    PMPI_Bcast(id, COMM_ID_LEN, MPI_BYTE, 0, local_comm);
    add_mpi_comm_hash_entry(newcomm, id);
    return id;
}

void* get_predefined_comm_id(MPI_Comm comm) {
    MPI_Comm mycomm = comm;
    int tmp = 0;
    memcpy(predefined_comm_id, &mycomm, sizeof(MPI_Comm));
    memcpy(predefined_comm_id+sizeof(MPI_Comm), &tmp, sizeof(int));
    return predefined_comm_id;
}

/*
 * Name the following functinos in a way that we can
 * use the above defined MACROs:
 *  - MPI_OBJ_ID(MPI_Comm, comm);
 *  - MPI_OBJ_RELEASE(MPI_Comm, comm);
 */
void* get_object_id_MPI_Comm(MPI_Comm *comm) {
    // check for predefined comm
    if((comm == NULL) || (*comm== MPI_COMM_NULL))
        return get_predefined_comm_id(MPI_COMM_NULL);
    else if((*comm == MPI_COMM_WORLD) || (*comm == MPI_COMM_SELF))
        return get_predefined_comm_id(*comm);

    // otherwise, check for hash table
    MPICommHash *entry = NULL;
    HASH_FIND(hh, hash_MPI_Comm, comm, sizeof(MPI_Comm), entry);
    if(entry && entry->id) {
        return entry->id;
    } else {
        // not possible
        if(!entry)
            printf("Not possible! cannot find MPI_Comm entry\n");
        else
            printf("Not possible! entry->id is NULL\n");
        // TODO
        return comm2id(comm);
    }
}
void object_release_MPI_Comm(MPI_Comm *comm) {
    if( (comm==NULL) || (*comm==MPI_COMM_NULL) || (*comm==MPI_COMM_SELF) || (*comm == MPI_COMM_WORLD) )
        return;

    MPICommHash *entry = NULL;
    HASH_FIND(hh, hash_MPI_Comm, comm, sizeof(MPI_Comm), entry);
    if(entry) {
        HASH_DEL(hash_MPI_Comm, entry);
        dlfree(entry->key);
        dlfree(entry->id);
        dlfree(entry);
    }
}

void object_cleanup_MPI_Comm() {
    MPICommHash *entry, *tmp;
    HASH_ITER(hh, hash_MPI_Comm, entry, tmp) {
        HASH_DEL(hash_MPI_Comm, entry);
        dlfree(entry->key);
        dlfree(entry->id);
        dlfree(entry);
    }
}
