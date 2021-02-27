#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>

//typedef void (*sighandler_t)(int);

//sighandler_t signal(int signum, sighandler_t handler);
//int atoi(const char *nptr);
//convert a string to an integer
int main(int argc, char **argv)
{
    int signum;
    int pid;
    char cmd[128] = {0};

    signum = atoi(argv[1]);
    pid = atoi(argv[2]);

    printf("signum = %d, pid = %d\n", signum, pid);
    sprintf(cmd, "kill -%d %d", signum, pid);
    //kill(pid, signum);
    system(cmd);
    printf("send signal ok");
    return 0;
}
