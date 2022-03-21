#include <stdio.h>
#include "filelock.h"
#include <unistd.h>

int main()
{
    int lock_id = flock_open("/tmp/lock_file.txt");

    if(lock_id<0){
        printf("error: open()\n");
    }

    while(1){
        printf("p2_wait()\n");
        flock_lock(lock_id);
        printf("p2_lock()\n");
        sleep (1);
        flock_unlock(lock_id);
        printf("p2_unlock()\n");
    }
    flock_close(lock_id);
    return 0;
}
