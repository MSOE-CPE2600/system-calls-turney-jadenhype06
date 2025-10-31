/* 
* Filename: pinfo.c
* Author: Jaden Hipe
* Date: 10/31/2025
* Compile info: make pinfo.c
* Description: Provides pid information using system calls.
*/ 

#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    pid_t mypid = getpid();

    //Print out pid info
    printf("Process Priority: %d\n", getpriority(mypid));
    printf("Scheduling Method: %d\n", sched_getscheduler(mypid));
    return 0;
}