/* 
* Filename: finfo.c
* Author: Jaden Hipe
* Course Section: 112
* Date: 11/3/2025
* Compile info: make finfo.c
* Description: Returns info about a specified file on the command line.
*/ 


#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[])
{
    struct stat sb;
    char *file_type;

    if (lstat(argv[1], &sb) == -1)
    {
        printf("Error: File not found.\n");
        exit(1);
    }
    //File type
    //Source: man7.org/linux/man-pages/man2/fstat.2.html
    switch (sb.st_mode & S_IFMT) {
        case S_IFBLK:  file_type = "Block special";    break;
        case S_IFCHR:  file_type = "Character special"; break;
        case S_IFIFO:  file_type = "FIFO special";      break;
        case S_IFREG:  file_type = "Regular";           break;
        case S_IFDIR:  file_type = "Directory";         break;
        case S_IFLNK:  file_type = "Symbolic Link";     break;
        case S_IFSOCK: file_type = "Socket";            break;
        default:       file_type = "Unknown";           break;
    
    }
    printf("File Type: %s\n", file_type);

    //Owner file permissions
    printf("Permissions:\n");
    //st_mode is a lot of bits, so check them using bitwise &
    if (sb.st_mode & S_IRUSR)
    {
        printf("Owner has read permissions.\n");
    }
    //W for write
    if (sb.st_mode & S_IWUSR)
    {
        printf("Owner has write permissions.\n");
    }
    //X for execute
    if (sb.st_mode & S_IXUSR)
    {
        printf("Owner has execute permissions.\n");
    }

    //Owner
    printf("Owner ID: %d\n", sb.st_uid);

    //File Size
    printf("File Size: %ld Bytes\n", sb.st_size);
    
    //Last Modified
    printf("Last Modified: %s", ctime(&sb.st_mtime));
    return 0;
}