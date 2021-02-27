#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    //int execl(const char *path, const char *arg, ... /* (char  *) NULL */);
    if(execl("ls", "ls", "-l", "-a", NULL) == -1){
        printf("use ls failed!\n");
        perror("Why");
    }
    printf("\n......................use ls faied........................\n");

    return 0;
}
