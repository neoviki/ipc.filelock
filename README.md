## IPC File lock library 

IPC File Lock libary based on flock

## Source

    - src/ipc_flock.c

## Example

    - example/p1.c
    - example/p2.c

## Operation Summary

    Case 1: 

        If process1 locks, process2 will be blocked until process1 unlocks.

    Case 2:

        If process1 locks and terminates abruptly. The lock created by process1 will be automatically unlocked. 
        Process2 will not be blocked foreever. ( This is one important feature of this lock )


## Latency

    I didn't research on the latency yet.


## Use Case


    1. We can use this locking to provide exclusive access to shared memory.  


