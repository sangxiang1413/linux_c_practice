#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
int main()
{
    pid_t pid;
    int cnt = 0;
    pid = fork();
    int status = 10;
    if(pid > 0){
        wait(&status);
        printf("child quit, ststus = %d\n", /*WIFEXITED(status)*/ WEXITSTATUS(status));
        while(1){
            printf("This is a father print, pid = %d\n", getpid());
            sleep(1);
            printf("cnt = %d\n", cnt);
         }
    }

    else if(pid == 0){
        while(1){
            printf("This is a child print, pid = %d\n", getpid());
            sleep(1);
            cnt++;
            if(cnt == 5){
                //break;
                exit(3);
            }
        }
    }
    return 0;
}
