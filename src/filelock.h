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
}filelock_t;

filelock_t *flock_open(char *fname);
int flock_lock(filelock_t *fl);
int flock_unlock(filelock_t *fl);
int flock_close(filelock_t *fl);
#endif
