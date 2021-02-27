#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    pid_t pid;
    pid = getpid();
    fork();
    printf("My pid is %d\n", pid);


    return 0;
}
