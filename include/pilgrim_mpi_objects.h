/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#ifndef _PILGRIM_MPI_OBJECTS_H_
#define _PILGRIM_MPI_OBJECTS_H_
#include <stdio.h>
#include <stdbool.h>
#include "mpi.h"
#include "uthash.h"
#include "utlist.h"
#include "dlmalloc-2.8.6.h"

/**
 * 1. Following structs, MACROS and functions
 * are for general MPI objects such as MPI_Info,
 * MPI_Win, etc.
 */

#define MPI_OBJ_NODE_STRUCT(Type)           \
    typedef struct _ObjNode_##Type {        \
        int id;                             \
        struct _ObjNode_##Type *prev;       \
        struct _ObjNode_##Type *next;       \
    } ObjNode_##Type;


#define MPI_OBJ_HASH_STRUCT(Type)           \
    typedef struct _ObjHsah_##Type {        \
        void *key;                          \
        ObjNode_##Type *id_node;            \
        UT_hash_handle hh;                  \
    } ObjHash_##Type;


#define MPI_OBJ_DECLARE(Type)                                           \
    MPI_OBJ_NODE_STRUCT(Type);                                          \
    MPI_OBJ_HASH_STRUCT(Type);                                          \
    ObjHash_##Type* get_hash_entry_##Type(const Type *obj);             \
    int  get_object_id_##Type(const Type *obj);                         \
    void object_release_##Type(const Type *obj);                        \
    void object_cleanup_##Type();


/**
 * Only three MARCOs are used by the outsiders.
 *
 * MPI_OBJ_ID() will return the id for a given MPI object
 * If the object does not have a entry in the hash table,
 * then this must be the first time the object is created,
 * we will create a entry in the hash table and assign it
 * an ID.
 *
 * MPI_OBJ_RELEASE() should be called upon _free() functions
 * (e.g., MPI_Info_free()). This function frees an entry in
 * the hash table and put the ID back to the free list.
 *
 * MPI_OBJ_CLEANUP_ALL() destorys all allocated resources for
 * all MPI objects.
 */
#define MPI_OBJ_ID(Type, obj) get_object_id_##Type(obj)
#define MPI_OBJ_RELEASE(Type, obj) object_release_##Type(obj)
#define MPI_OBJ_CLEANUP_ALL()                                           \
    object_cleanup_MPI_Datatype();                                      \
    object_cleanup_MPI_Info();                                          \
    object_cleanup_MPI_File();                                          \
    object_cleanup_MPI_Win();                                           \
    object_cleanup_MPI_Group();                                         \
    object_cleanup_MPI_Op();                                            \
    object_cleanup_MPI_Message();                                       \
    object_cleanup_MPI_Comm();                                          \
    object_cleanup_MPI_Request();

MPI_OBJ_DECLARE(MPI_Datatype);
MPI_OBJ_DECLARE(MPI_Info);
MPI_OBJ_DECLARE(MPI_File);
MPI_OBJ_DECLARE(MPI_Win);
MPI_OBJ_DECLARE(MPI_Group);
MPI_OBJ_DECLARE(MPI_Op);
MPI_OBJ_DECLARE(MPI_Message);
MPI_OBJ_DECLARE(MPI_Errhandler);


// MPI_Request and MPI_Comm need special implementations as below
/*
 * ======================================================================
 *                          MPI_Request
 * ======================================================================
 *
 */
typedef struct RequestNode_t {
    int id;
    struct RequestNode_t *prev;
    struct RequestNode_t *next;
} RequestNode;

typedef struct RequestNodeHash_t {
    void *key;  // call signature as the key for free id list
    int key_len;
    RequestNode* free_ids;
    UT_hash_handle hh;
} RequestNodeHash;

typedef struct RequestHash_t {
    void *key;
    int key_len;
    void *signature;
    int signature_len;
    RequestNode* req_node;
    bool any_source;
    bool any_tag;
    UT_hash_handle hh;
} RequestHash;

RequestHash* request_hash_entry(MPI_Request* request);
int create_request_id(MPI_Request* req, bool from_universal_pool, int func_id, int src_or_dst, int tag, int comm);

/*
 * Name the following functinos in a way that
 * we can use the above defined MACROs:
 *  - MPI_OBJ_ID(MPI_Comm, comm);
 *  - MPI_OBJ_RELEASE(MPI_Comm, comm);
 */
int  get_object_id_MPI_Request(MPI_Request *request);
void object_release_MPI_Request(MPI_Request* request);
void object_cleanup_MPI_Request();


/*
 * ======================================================================
 *                          MPI_Comm
 * ======================================================================
 *
 */
typedef struct MPICommHash_t {
    void *key;
    int id;                     // (newcomm, global rank of newcomm's rank 0)
    UT_hash_handle hh;
} MPICommHash;

void add_mpi_comm_hash_entry(MPI_Comm *newcomm, int id);
int generate_intracomm_id(MPI_Comm *newcomm);
int generate_intercomm_id(MPI_Comm local_comm, MPI_Comm *newcomm, int tag);
int get_predefined_comm_id(MPI_Comm comm);

/*
 * Name the following functinos in a way that
 * we can use the above defined MACROs:
 *  - MPI_OBJ_ID(MPI_Comm, comm);
 *  - MPI_OBJ_RELEASE(MPI_Comm, comm);
 */
int get_object_id_MPI_Comm(MPI_Comm *comm);
void object_release_MPI_Comm(MPI_Comm *comm);
void object_cleanup_MPI_Comm();


#endif
