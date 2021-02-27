#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    pid_t pid;
    pid_t pid2;
    pid = getpid();
    printf("before fork: pid = %d\n", pid);
    fork();
    pid2 = getpid();
    if(pid == pid2){
        printf("This is a father print\n");
    }else{
        printf("This is child print, child pid = %d\n", pid2);
    }

    return 0;
}
