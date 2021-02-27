#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
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

    write(fd, buf, strlen(buf));
    close(fd);

    return 0;
}

