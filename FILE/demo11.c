#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int fd;
    char * buf = "This is a test!";
    //int creat(const char *pathname, mode_t mode);
    fd = creat("/root/MyWork/file1", S_IRWXU);
    return 0;
}

