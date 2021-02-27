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
    fd = open("./file1", O_RDWR);
    if( fd == -1 ){
        printf("Open file1 failed!\n");
        fd = open("./file1", O_RDWR | O_CREAT, 0600);
        if(fd > 0){
            printf("Creat file1 sucess!\n");
            printf("fd = %d\n", fd);
        }
    }

    int n_write = write(fd, buf, strlen(buf));
    if(n_write != -1){
        printf("Write %d byte to file1\n", n_write);
    }else{
        printf("Write failed!\n");
    }
    lseek(fd, 0, SEEK_SET);
    char * readBuf = (char *)malloc(sizeof(char)*n_write +1);
    int n_read = read(fd, readBuf, n_write);

    printf("read %d byte ,content:%s\n", n_read, readBuf);
    close(fd);

    return 0;
}

