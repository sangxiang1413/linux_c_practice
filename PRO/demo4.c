#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    pid_t pid;
    pid = getpid();
    printf("before fork: pid = %d\n", pid);
    fork();

    if(pid == getpid()){
        printf("This is a father print\n");
    }else{
        printf("This is child print, child pid = %d\n", getpid());
    }

    return 0;
}
