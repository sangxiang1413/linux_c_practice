#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    //int execl(const char *path, const char *arg, ... /* (char  *) NULL */);
    char * argv[] = {"ps", "-aux", NULL};
    if(execvp("ps", argv) == -1){
        printf("use ps failed!\n");
        perror("Why");
    }
    printf("\n......................use ps faied........................\n");

    return 0;
}
