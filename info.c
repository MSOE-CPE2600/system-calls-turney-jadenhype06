/* 
* Filename: info.c
* Author: Jaden Hipe
* Date: 10/30/2025
* Compile info: make info.c
* Description: Provides maintenance information using system calls.
*/ 

#include <time.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc, char* argv[])
{
    //Using clock_gettime
    struct timespec spec;
    int time = clock_gettime(CLOCK_REALTIME, &spec);
    printf("Time (ns): %ld\n", spec.tv_nsec);
    

    //uname
    struct utsname machine_info;
    uname(&machine_info);
    printf("Network Name: %s\n",machine_info.nodename);
    printf("System Name: %s\n",machine_info.sysname);
    printf("OS Release: %s\n",machine_info.release);
    printf("OS Version: %s\n",machine_info.version);
    printf("Hardware Type: %s\n",machine_info.machine);

    // //Number of Processors
    printf("Number of Processors: %d\n", get_nprocs());

    //Number of Bytes
    long phys_bytes = sysconf(_SC_PHYS_PAGES) * getpagesize();
    long free_bytes = sysconf(_SC_AVPHYS_PAGES) * getpagesize();
    printf("Amount of Physical Memory: %ld\n", phys_bytes);
    printf("Amount of Free Memory: %ld\n", free_bytes);

    return 0;
}

