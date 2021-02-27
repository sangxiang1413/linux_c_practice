#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

//int mkfifo(const char *pathname, mode_t mode);

int main()
{
    char str[30] = {0};
    int n_read;
    if((mkfifo("./file", 0600) == -1) && errno == EEXIST){
        printf("mkfifo failed!\n");
        perror("Why");
    }
    int fd = open("./file", O_RDONLY);
    printf("open succese!\n");
    while(1){
        n_read = read(fd, str, 30);
        printf("read %d byte from fifo, content: %s\n", n_read, str);
    }
    close(fd);
    return 0;
}

