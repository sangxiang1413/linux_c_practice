#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    pid_t pid;
    pid = getpid();
    printf("My pid is %d\n", pid);

    while(1);

    return 0;
}
