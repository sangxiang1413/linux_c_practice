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
    fd = open("./file1", O_RDWR | O_APPEND);
    printf("fd = %d\n",  fd);
        //ssize_t write(int fd, const void *buf, size_t count);
    int n_write = write(fd, buf, strlen(buf));
    if(n_write != -1){
        printf("Write %d byte to file1\n", n_write);
    }else{
        printf("Write failed!\n");
    }

     close(fd);

    return 0;
}

