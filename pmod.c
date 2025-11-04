/* 
* Filename: pinfo.c
* Author: Jaden Hipe
* Date: 11/3/2025
* Compile info: make pmod.c
* Description: Reduces a pid priority by 10, sleeps for 1.8 billion nanoseconds, and prints an exit message.
*/ 

#include <unistd.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[])
{
    //Reduce the priority by 10, lower priority is higher value
    printf("New priority is: %d\n",nice(10));

    //Sleep time is 1837272638, nsec can only hold up to 1 trillion - 1
    struct timespec spec;
    spec.tv_sec = 1;
    spec.tv_nsec = 837272638;
    
    printf("Sleeping...\n");
    nanosleep(&spec, NULL);
    printf("End of Program\n");
    return 0;
}