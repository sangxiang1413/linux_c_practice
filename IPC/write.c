#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

//int mkfifo(const char *pathname, mode_t mode);

int main()
{
    int cnt = 0;
    char * str = "I'm from fifo";
    int fd = open("./file", O_WRONLY);//O_WRONLY
    printf("write open succese!\n");
    while(1){
        int n_write = write(fd, str, strlen(str));
        sleep(1);
        //cnt++;

        if(cnt == 5){
            break;
        }
    }

    close(fd);
    return 0;
}

