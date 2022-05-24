/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */
#define _GNU_SOURCE
#include <stdio.h>
#include <pthread.h>
#include <dlfcn.h>
#include "pilgrim_pthread_hooks.h"
#include "pilgrim_utils.h"
#include "uthash.h"


typedef struct thread_tid_entry {
    pthread_t thread;   // pthread_t as key
    int       tid;      // symbolic tid as value
    UT_hash_handle hh;
}  thread_tid_entry_t;

static int          current_tid;
thread_tid_entry_t* thread2tid;
pthread_rwlock_t    uthash_lock = PTHREAD_RWLOCK_INITIALIZER;

/*
void thread_tid_entry_destroy(pthread_t thread) {
    pthread_rwlock_wrlock(&uthash_lock);
    thread_tid_entry *entrh;
    HASH_FIND(hh, thread2tid, thread, sizeof(pthread_t), entry);
    if(entry) {
        HASH_DELETE(hh, thread2tid, entry);
    }
    pthread_rwlock_unlock(&uthash_lock);
}
*/

int pilgrim_pthread_add_get_tid() {
#ifdef ENABLE_THREAD_ID
    thread_tid_entry_t *entry = NULL;

    pthread_rwlock_rdlock(&uthash_lock);
    pthread_t thread = pthread_self();
    HASH_FIND(hh, thread2tid, &thread, sizeof(pthread_t), entry);
    pthread_rwlock_unlock(&uthash_lock);

    if(entry)
        return entry->tid;

    // Reached here, suggesting that this pthread_t is seen the
    // the first time, assign it a symbolic tid and add the entry
    // to the hash table

    // pthread_t not seen before, add it to the hash table
    pthread_rwlock_wrlock(&uthash_lock);

    entry = pilgrim_malloc(sizeof(thread_tid_entry_t));
    memcpy(&entry->thread, &thread, sizeof(pthread_t));
    entry->tid = current_tid++;

    HASH_ADD(hh, thread2tid, thread, sizeof(pthread_t), entry);

    pthread_rwlock_unlock(&uthash_lock);

    return entry->tid;
#else
    return 0;
#endif
}


// ---------------------------
// Start of hooks
// ---------------------------
//
/* pthread hooks are not used for now.
 * Currently, we simply map pthread_self() to a local symbolic
 */
/*
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void*), void *arg) {
    MAP_OR_FAIL(pthread_create);
    int res = PILGRIM_REAL_CALL(pthread_create)(thread, attr, start_routine, arg);
    printf("intercepted pthread_create(), thread: %ld\n", *thread);
    return res;
}

void pthread_exit(void *value_ptr) {
    MAP_OR_FAIL(pthread_exit);
    printf("intercepted pthread_exit()\n");
    // release symbolic id ?
    PILGRIM_REAL_CALL(pthread_exit)(value_ptr);
}

int pthread_join(pthread_t thread, void **value_ptr) {
    MAP_OR_FAIL(pthread_join);
    printf("intercepted pthread_join()\n");
    int res = PILGRIM_REAL_CALL(pthread_join)(thread, value_ptr);
    return res;
}

int pthread_detach(pthread_t thread) {
    MAP_OR_FAIL(pthread_detach);
    printf("intercepted pthread_detach()\n");
    int res = PILGRIM_REAL_CALL(pthread_detach)(thread);
    return res;
}

int pthread_rwlock_init(pthread_rwlock_t *rwlock, const pthread_rwlockattr_t *attr) {
    MAP_OR_FAIL(pthread_rwlock_init);
    printf("intercepted pthread_rwlock_init()\n");
    return PILGRIM_REAL_CALL(pthread_rwlock_init)(rwlock, attr);
}

int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr) {
    MAP_OR_FAIL(pthread_mutex_init);
    pthread_t thread = pthread_self();
    printf("%ld: intercepted pthread_mutex_init()\n", thread);
    return PILGRIM_REAL_CALL(pthread_mutex_init)(mutex, attr);
}

int pthread_cond_init(pthread_cond_t *cond, const pthread_condattr_t *attr) {
    MAP_OR_FAIL(pthread_cond_init);
    printf("intercepted pthread_cond_init()\n");
    return PILGRIM_REAL_CALL(pthread_cond_init)(cond, attr);
}

int pthread_cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex) {
    MAP_OR_FAIL(pthread_cond_wait);
    printf("intercepted pthread_cond_wait()\n");
    return PILGRIM_REAL_CALL(pthread_cond_wait)(cond, mutex);
}

int pthread_cond_timedwait(pthread_cond_t *cond,  pthread_mutex_t *mutex, const struct timespec *abstime) {
    MAP_OR_FAIL(pthread_cond_timedwait);
    printf("intercepted pthread_cond_timedwait()\n");
    return PILGRIM_REAL_CALL(pthread_cond_timedwait)(cond, mutex, abstime);
}

int pthread_mutex_lock(pthread_mutex_t *mutex) {
    MAP_OR_FAIL(pthread_mutex_lock);
    pthread_t thread = pthread_self();
    printf("%ld: intercepted pthread_mutex_lock()\n", thread);
    return PILGRIM_REAL_CALL(pthread_mutex_lock)(mutex);
}

int pthread_mutex_trylock(pthread_mutex_t *mutex) {
    MAP_OR_FAIL(pthread_mutex_trylock);
    printf("intercepted pthread_mutex_trylock()\n");
    return PILGRIM_REAL_CALL(pthread_mutex_trylock)(mutex);
}
*/
// ---------------------------
// End of hooks
// ---------------------------
