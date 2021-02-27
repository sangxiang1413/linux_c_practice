#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    printf("get system time :\n");

    //int execl(const char *path, const char *arg, ... /* (char  *) NULL */);
    if(execl("date", "date", NULL) == -1){
        printf("use date failed!\n");
        perror("Why");
    }
    printf("get time faied!\n");

    return 0;
}
