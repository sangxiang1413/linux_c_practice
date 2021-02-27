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
    char buf[128];
    int n_read = read(0, buf, 5);
    int n_write = write(1, buf, strlen(buf));
    printf("\ndone!\n");
    return 0;
}

