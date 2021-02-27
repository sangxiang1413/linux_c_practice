#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Test
{
    int a;
    char c;
};
int main()
{
    int fd;
    struct Test data1 = {100, 'a'};
    struct Test data2;
    fd = open("./file1", O_RDWR);
    if( fd == -1 ){
        printf("Open file1 failed!\n");
        fd = open("./file1", O_RDWR | O_CREAT, 0600);
        if(fd > 0){
            printf("Creat file1 sucess!\n");
            printf("fd = %d\n", fd);
        }
    }

    int n_write = write(fd, &data1, sizeof(struct Test));
    if(n_write != -1){
        printf("Write %d byte to file1\n", n_write);
    }else{
        printf("Write failed!\n");
    }

    lseek(fd, 0, SEEK_SET);
    int n_read = read(fd, &data2, sizeof(struct Test));

    printf("read data1.a :%d\ndata1.c :%c\n", data2.a, data2.c);
    close(fd);

    return 0;
}

