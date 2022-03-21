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
        printf("p1_wait()\n");
        flock_lock(fl);
        printf("p1_lock()\n");
        sleep (10);
        flock_unlock(fl);
        printf("p1_unlock()\n");
        sleep(2);
    }
    flock_close(fl);
    return 0;
}
