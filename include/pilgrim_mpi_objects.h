#ifndef _PILGRIM_MPI_OBJECTS_H_
#define _PILGRIM_MPI_OBJECTS_H_
#include <stdio.h>
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
    int* get_object_id_##Type(const Type *obj);                         \
    void object_release_##Type(const Type *obj);                        \
    void object_cleanup_##Type();


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
            dlfree(entry->key);                                         \
            HASH_DEL(hash_##Type, entry);                               \
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


/**
 * Only four three MARCOs are used by the outsiders.
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
    object_cleanup_MPI_Message();

#define MPI_OBJ_DEFINE_ALL()                                            \
    MPI_OBJ_DEFINE(MPI_Datatype);                                       \
    MPI_OBJ_DEFINE(MPI_Info);                                           \
    MPI_OBJ_DEFINE(MPI_File);                                           \
    MPI_OBJ_DEFINE(MPI_Win);                                            \
    MPI_OBJ_DEFINE(MPI_Group);                                          \
    MPI_OBJ_DEFINE(MPI_Op);                                             \
    MPI_OBJ_DEFINE(MPI_Message);

MPI_OBJ_DECLARE(MPI_Datatype);
MPI_OBJ_DECLARE(MPI_Info);
MPI_OBJ_DECLARE(MPI_File);
MPI_OBJ_DECLARE(MPI_Win);
MPI_OBJ_DECLARE(MPI_Group);
MPI_OBJ_DECLARE(MPI_Op);
MPI_OBJ_DECLARE(MPI_Message);



/**
 * 2. Here starts MPI_Request
 */
typedef struct RequestNode_t {
    int id;
    struct RequestNode_t *prev;
    struct RequestNode_t *next;
} RequestNode;

typedef struct RequestHash_t {
    void *key;
    int key_len;
    RequestNode* req_node;
    bool any_source;
    bool any_tag;
    UT_hash_handle hh;
} RequestHash;

RequestHash* request_hash_entry(MPI_Request* request);
int* request2id(MPI_Request* request, int source, int tag);
void free_request(MPI_Request* request);


#endif
