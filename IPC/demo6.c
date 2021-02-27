#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

//int mkfifo(const char *pathname, mode_t mode);

int main()
{

    if((mkfifo("./file", 0600) == -1) && errno == EEXIST){
        printf("mkfifo failed!\n");
        perror("Why");
    }
    int fd = open("./file", O_RDONLY);
    printf("open succese!\n");
    return 0;
}

