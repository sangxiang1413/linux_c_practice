#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    pid_t pid;
    pid = getpid();
    fork();
    printf("My pid is %d current pro is :%d\n", pid, getpid());


    return 0;
}
