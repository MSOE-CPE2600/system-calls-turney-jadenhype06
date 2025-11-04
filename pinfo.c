/* 
* Filename: pinfo.c
* Author: Jaden Hipe
* Course Section: 112
* Date: 11/3/2025
* Compile info: make pinfo.c
* Description: Provides pid information using system calls.
*/ 

#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int priority;
    int sched;
    char *policy;
    //Case of printing info of current process
    if (argc == 1)
    {
        pid_t curr_pid = getpid();
        priority = getpriority(PRIO_PROCESS, curr_pid);
        sched = sched_getscheduler(curr_pid);

        if (sched == SCHED_OTHER)
            {
                policy = "SCHED_OTHER";
            }
        else if(sched == SCHED_BATCH)
            {
                policy = "SCHED_BATCH";
            }
        else if(sched == SCHED_IDLE)
            {
                policy = "SCHED_IDLE";
            }
        else if(sched == SCHED_FIFO)
            {
                policy = "SCHED_FIFO";
            }
        else if(sched == SCHED_RR)
            {
                policy = "SCHED_RR";
            }
        printf("Priority: %d\n", priority);
        printf("Scheduling Method: %s\n", policy);
    }
    //User specified a pid 
    else if (argc == 2)
    {
        //get console arg input
        int input = atoi(argv[1]);
        pid_t mypid = (pid_t)input;

        //Get pid info
        priority = getpriority(PRIO_PROCESS, mypid);
        sched = sched_getscheduler(mypid);
        
        if (priority == -1 || sched == -1)
        {
        printf("Error: pid not found.\n");
        exit(1);
        }
        else 
        {
            if (sched == SCHED_OTHER)
            {
                policy = "SCHED_OTHER";
            }
            else if(sched == SCHED_BATCH)
            {
                policy = "SCHED_BATCH";
            }
            else if(sched == SCHED_IDLE)
            {
                policy = "SCHED_IDLE";
            }
            else if(sched == SCHED_FIFO)
            {
                policy = "SCHED_FIFO";
            }
            else if(sched == SCHED_RR)
            {
                policy = "SCHED_RR";
            }
        }
        printf("Priority: %d\n", priority);
        printf("Scheduling Method: %s\n", policy);
    }
    return 0;
}