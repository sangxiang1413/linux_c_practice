#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

//int mkfifo(const char *pathname, mode_t mode);

int main()
{

    int fd = open("./file", O_WRONLY);//O_WRONLY
    printf("write open succese!\n");
    return 0;
}

