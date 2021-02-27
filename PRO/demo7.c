#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    pid_t pid;
    pid_t pid2;
    pid_t retpid;
    pid = getpid();
    printf("before fork: pid = %d\n", pid);
    retpid = fork();
    pid2 = getpid();
    if(pid == pid2){
        printf("This is a father print! retpid =  %d\n", retpid);
    }else{
        printf("This is child print, child pid = %d retpid = %d\n", getpid(), retpid);
    }

    return 0;
}
