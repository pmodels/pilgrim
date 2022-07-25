/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#ifndef _PILGRIM_PTHREAD_HOOKS_H_
#define _PILGRIM_PTHREAD_HOOKS_H_

#define _GNU_SOURCE
#include <stdio.h>
#include <pthread.h>
#include <dlfcn.h>


/*
 * Declare the function signatures for real functions
 * i.e. The real function point to fwrite would be defined as __real_fwrite
 */
#define PILGRIM_REAL_DECL(name, ret, args) ret (*__real_##name) args;

/* Point __real_func to the real funciton using dlsym() */
#define MAP_OR_FAIL(func)                                                   \
    if (!(__real_##func)) {                                                 \
        __real_##func = dlsym(RTLD_NEXT, #func);                            \
        if (!(__real_##func)) {                                             \
            printf("Recorder failed to map symbol: %s\n", #func);           \
        }                                                                   \
    }

/*
 * Call the real funciton
 * Before call the real function, we need to make sure its mapped by dlsym()
 * So, every time we use this marco directly, we need to call MAP_OR_FAIL before it
 */
#define PILGRIM_REAL_CALL(func) __real_##func

PILGRIM_REAL_DECL(pthread_create, int, (pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void*), void *arg));
PILGRIM_REAL_DECL(pthread_exit, void, (void *value_ptr));
PILGRIM_REAL_DECL(pthread_join, int, (pthread_t thread, void *value_ptr));
PILGRIM_REAL_DECL(pthread_detach, int, (pthread_t thread));

PILGRIM_REAL_DECL(pthread_mutex_init, int, (pthread_mutex_t *, const pthread_mutexattr_t *));
PILGRIM_REAL_DECL(pthread_rwlock_init, int, (pthread_rwlock_t *, const pthread_rwlockattr_t *));
PILGRIM_REAL_DECL(pthread_cond_init, int, (pthread_cond_t *, const pthread_condattr_t *));
PILGRIM_REAL_DECL(pthread_cond_wait, int, (pthread_cond_t *cond, pthread_mutex_t *mutex));
PILGRIM_REAL_DECL(pthread_cond_timedwait, int, (pthread_cond_t *cond, pthread_mutex_t *mutex, const struct timespec *abstime));
PILGRIM_REAL_DECL(pthread_mutex_lock, int, (pthread_mutex_t *mutex));
PILGRIM_REAL_DECL(pthread_mutex_unlock, int, (pthread_mutex_t *mutex));
PILGRIM_REAL_DECL(pthread_mutex_trylock, int, (pthread_mutex_t *mutex));

// Get the symbolic id of pthread_t
int pilgrim_pthread_add_get_tid();

#endif
