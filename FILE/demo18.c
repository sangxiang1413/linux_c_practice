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
    struct Test data1[] = {{100, 'a'}, {400, 'c'}};
    struct Test data2[2];
    fd = open("./file1", O_RDWR);
    if( fd == -1 ){
        printf("Open file1 failed!\n");
        fd = open("./file1", O_RDWR | O_CREAT, 0600);
        if(fd > 0){
            printf("Creat file1 sucess!\n");
            printf("fd = %d\n", fd);
        }
    }

    int n_write = write(fd, &data1, sizeof(struct Test) * 2);
    if(n_write != -1){
        printf("Write %d byte to file1\n", n_write);
    }else{
        printf("Write failed!\n");
    }

    lseek(fd, 0, SEEK_SET);
    int n_read = read(fd, &data2, sizeof(struct Test) * 2);

    printf("read data1[0].a :%d\nread data1[0].c :%c\n", data2[0].a, data2[0].c);
    printf("read data1[1].a :%d\nread data1[1].c :%c\n", data2[1].a, data2[1].c);
    close(fd);

    return 0;
}

