#include <stdio.h>
#include "filelock.h"
#include <unistd.h>

int main()
{
    filelock_t *fl = flock_open("/tmp/lock_file.txt");

    if(fl==NULL){
        printf("error: open()\n");
        return -1;
    }

    while(1){
        printf("p2_wait()\n");
        flock_lock(fl);
        printf("p2_lock()\n");
        sleep (1);
        flock_unlock(fl);
        printf("p2_unlock()\n");
        sleep (1);
    }
    flock_close(fl);
    return 0;
}
