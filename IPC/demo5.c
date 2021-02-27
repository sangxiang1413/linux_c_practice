#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
//int mkfifo(const char *pathname, mode_t mode);

int main()
{

    if((mkfifo("./file", 0600) == -1) && errno == EEXIST){
        printf("mkfifo failed!\n");
        perror("Why");
    }
    else{
        if(errno == EEXIST){
            printf("has file!\n");
        }
        else{
            printf("mkfifo succese!\n");
        }
    }
    return 0;
}

