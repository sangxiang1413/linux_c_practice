#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    int signum;
    int pid;

    signum = atoi(argv[1]);
    pid = atoi(argv[2]);

    union sigval value;
    value.sival_int = 100;
    //int sigqueue(pid_t pid, int sig, const union sigval value);
    sigqueue(pid, signum, value);
    printf("%d.done\n", getpid());


    return 01;
}
