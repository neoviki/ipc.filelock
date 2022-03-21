/* File lock library with flock
 *
 *      Author  : Viki (a) Vignesh Natarajan
 *      Contact : neoviki.com
 */

#ifndef FILE_LOCK_H
#define FILE_LOCK_H
int flock_open(char *fname);
int flock_lock(int fd);
int flock_unlock(int fd);
int flock_close(int fd);
#endif
