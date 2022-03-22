#include <stdio.h>
#include "ipc_flock.h"
#include <unistd.h>

int main()
{
    int ctr = 0;
    ipc_flock_t *fl = ipc_flock_open("/tmp/lock_file.txt");
    
    if(fl==NULL){
        printf("error: open()\n");
        return -1;
    }

    while(ctr < 100){
        ctr++;
        printf("p1_wait()\n");
        ipc_flock_lock(fl);
        printf("p1_lock()\n");
        sleep (10);
        ipc_flock_unlock(fl);
        printf("p1_unlock()\n");
        sleep(10);
    }
    ipc_flock_close(fl);
    return 0;
}
