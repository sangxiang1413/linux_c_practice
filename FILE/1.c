#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd;
    fd = open("./file1", O_RDWR);
    if( fd == -1 ){
        printf("Open file1 failed!\n");
        fd = open("./file1", O_RDWR | O_CREAT, 0600);
        if(fd > 0){
            printf("Creat file1 sucess!\n");
        }
    }


    return 0;
}

