#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

//int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
/*struct sigaction {
    void     (*sa_handler)(int);
    void     (*sa_sigaction)(int, siginfo_t *, void *);
    sigset_t   sa_mask;
    int        sa_flags;
    void     (*sa_restorer)(void);
};*/
void handler(int signum, siginfo_t *info, void *context)
{
    printf("get signum = %d\n", signum);

    if(context != NULL){
        printf("get data = %d\n", info->si_int);
        printf("get data = %d\n", info->si_value.sival_int);
        printf("from :%d\n", info->si_pid);
    }
}
int main()
{
    printf("pid = %d\n", getpid());
    struct sigaction act;
    act.sa_sigaction = handler;
    act.sa_flags = SA_SIGINFO;//be able to get message
    sigaction(SIGUSR1, &act, NULL);
    while(1);
    return 0;
}
