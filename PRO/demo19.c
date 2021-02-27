#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    //int execl(const char *path, const char *arg, ... /* (char  *) NULL */);
    if(execl("/bin/ls", "ls", "-l", NULL) == -1){
        printf("use ls failed!\n");
    }
    printf("\n...................end........................\n");

    return 0;
}
