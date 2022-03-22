/* File lock library with flock
 *
 *      Author  : Viki (a) Vignesh Natarajan
 *      Contact : neoviki.com
 */

#ifndef FILE_LOCK_H
#define FILE_LOCK_H
#define FILE_NAME_LEN 256
typedef struct{
    int fd;
    char fname[FILE_NAME_LEN];
}ipc_flock_t;

ipc_flock_t *ipc_flock_open(char *fname);
int ipc_flock_lock(ipc_flock_t *fl);
int ipc_flock_unlock(ipc_flock_t *fl);
int ipc_flock_close(ipc_flock_t *fl);
#endif
