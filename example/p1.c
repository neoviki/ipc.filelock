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
        printf("p1_wait()\n");
        flock_lock(lock_id);
        printf("p1_lock()\n");
        sleep (10);
        flock_unlock(lock_id);
        printf("p1_unlock()\n");
        sleep(2);
    }
    flock_close(lock_id);
    return 0;
}
