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
    int data = 100;
    int data2 = 0;
    fd = open("./file1", O_RDWR);
    if( fd == -1 ){
        printf("Open file1 failed!\n");
        fd = open("./file1", O_RDWR | O_CREAT, 0600);
        if(fd > 0){
            printf("Creat file1 sucess!\n");
            printf("fd = %d\n", fd);
        }
    }

    int n_write = write(fd, &data, sizeof(int));
    if(n_write != -1){
        printf("Write %d byte to file1\n", n_write);
    }else{
        printf("Write failed!\n");
    }
    lseek(fd, 0, SEEK_SET);
    int n_read = read(fd, &data2, sizeof(int));

    printf("read %d\n", data2);
    close(fd);

    return 0;
}

