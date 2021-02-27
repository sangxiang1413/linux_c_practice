#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd;
    fd = open("./file1", O_RDWR | O_CREAT | O_EXCL, 0600);
    if(fd == -1){
        printf("file1 cunzai\n");
    }else{
        printf("file1 not cunzai\n");
    }

    return 0;
}

