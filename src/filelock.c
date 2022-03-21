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

filelock_t *flock_open(char *fname)
{
    if(!fname) return NULL;

    filelock_t *fl = (filelock_t *) calloc(1, sizeof(filelock_t));

    if(!fl) {
        printf("OOM\n");
        return NULL;
    }

    fl->fd  = open (fname, O_CREAT | O_RDONLY, 0666);

    if(fl->fd < 0){
        free(fl);
        printf("error: creating file (%s)\n", fname);
        return NULL;
    }	

    return fl;
}

int flock_lock(filelock_t *fl)
{
    int ret;
    if(!fl) return -1;
    while(1){
        ret = flock(fl->fd, LOCK_EX);
        if(ret == 0) return 0;
        //10ms
        usleep(10000);
    }
    return 0;
}

int flock_unlock(filelock_t *fl)
{
    if(!fl) return -1;
    flock(fl->fd, LOCK_UN);
    return 0;
}

int flock_close(filelock_t *fl)
{
    if(!fl) return -1;
    if(fl->fd<0) return -1;
    close(fl->fd);
    free(fl);
    return 0;
}
