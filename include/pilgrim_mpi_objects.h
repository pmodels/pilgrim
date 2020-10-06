#include <stdio.h>
#include "mpi.h"
#include "uthash.h"
#include "utlist.h"
#include "dlmalloc-2.8.6.h"

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

#define MPI_OBJ_CREATE(Type)                \
    MPI_OBJ_NODE_STRUCT(Type);              \
    MPI_OBJ_HASH_STRUCT(Type);              \
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
    void on_object_release_##Type(const Type *obj) {                    \
        ObjHash_##Type *entry = get_hash_entry_##Type(obj);             \
        if(entry) {                                                     \
            /* add the id back to the free list */                      \
            DL_APPEND(list_##Type, entry->id_node);                     \
            dlfree(entry->key);                                         \
            HASH_DEL(hash_##Type, entry);                               \
        }                                                               \
    }


#define MPI_OBJ_ID(Type, obj) get_object_id_##Type(obj)
#define MPI_OBJ_RELEASE(Type, obj) on_object_release_##Type(obj)


MPI_OBJ_CREATE(MPI_Datatype);
MPI_OBJ_CREATE(MPI_Info);
MPI_OBJ_CREATE(MPI_File);
MPI_OBJ_CREATE(MPI_Win);
MPI_OBJ_CREATE(MPI_Group);
MPI_OBJ_CREATE(MPI_Op);
MPI_OBJ_CREATE(MPI_Message);
MPI_OBJ_CREATE(MPI_Errhandler);
MPI_OBJ_CREATE(MPI_Comm_delete_attr_function);
MPI_OBJ_CREATE(MPI_Comm_errhandler_function);
MPI_OBJ_CREATE(MPI_Comm_copy_attr_function);
MPI_OBJ_CREATE(MPI_Copy_function);
MPI_OBJ_CREATE(MPI_Grequest_query_function);
MPI_OBJ_CREATE(MPI_Grequest_cancel_function);
MPI_OBJ_CREATE(MPI_Grequest_free_function);
MPI_OBJ_CREATE(MPI_File_errhandler_function);
MPI_OBJ_CREATE(MPI_Datarep_conversion_function);
MPI_OBJ_CREATE(MPI_Datarep_extent_function);
MPI_OBJ_CREATE(MPI_Delete_function);
MPI_OBJ_CREATE(MPI_Win_delete_attr_function);
MPI_OBJ_CREATE(MPI_Win_copy_attr_function);
MPI_OBJ_CREATE(MPI_Win_errhandler_function);
MPI_OBJ_CREATE(MPI_User_function);

/*
int main() {
    MPI_Datatype t = MPI_INT;
    int *id = MPI_OBJ_ID(MPI_Datatype, &t);
    printf("id: %d\n", *id);

    id = MPI_OBJ_ID(MPI_Datatype, &t);
    printf("id: %d\n", *id);


    on_object_release_MPI_Datatype(&t);

    return 0;
}
*/

