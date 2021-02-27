#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    //int execl(const char *path, const char *arg, ... /* (char  *) NULL */);
    if(execl("/bin/ls", "ls", "-l", "-a", NULL) == -1){
        printf("use ls failed!\n");
    }
    printf("\n......................use ls faied........................\n");

    return 0;
}
