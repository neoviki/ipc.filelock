/* File lock library with flock
 *
 *      Author  : Viki (a) Vignesh Natarajan
 *      Contact : neoviki.com
 */
#include <stdio.h>
#include <sys/file.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "filelock.h"

int flock_open(char *fname)
{
    int fd;
    if(!fname) return -1;

    fd  = open (fname, O_CREAT | O_RDONLY, 0666);

    if(fd < 0){
        printf("error: creating file (%s)\n", fname);
        return -1;
    }	

    return fd;
}

int flock_lock(int fd)
{
    int ret;
    while(1){
        ret = flock(fd, LOCK_EX);
        if(ret == 0) return 0;
        usleep(10000);
    }
    return 0;
}

int flock_unlock(int fd)
{
    flock(fd, LOCK_UN);
    return 0;
}

int flock_close(int fd)
{
    if(fd<0) return -1;
    close(fd);
    return 0;
}
