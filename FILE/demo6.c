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
    fd = open("./file1", O_RDWR);
    int n = lseek(fd, 0, SEEK_END);
    printf("f0ile1 has %d byte\n", n);
    close(fd);
    return 0;
}

