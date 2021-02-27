#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    pid_t pid;
    pid = fork();

    if(pid > 0){
        printf("This is a father print! father pid = %d\n", getpid());
    }else{
        printf("This is child print, child pid = %d\n", getpid());
    }

    return 0;
}
