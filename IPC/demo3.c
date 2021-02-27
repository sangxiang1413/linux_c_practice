#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
//int mkfifo(const char *pathname, mode_t mode);

int main()
{
    int ret = mkfifo("./file", 0600);
    if(ret == 0){
        printf("mkfifo succese!\n");
    }else if(ret == -1){
        printf("mkfifo failed!\n");
        perror("Why");
    }
    return 0;
}

