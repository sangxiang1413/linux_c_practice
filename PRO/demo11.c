#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    pid_t pid;
    pid = vfork();
    if(pid > 0){
        while(1){
            printf("This is a father print, pid = %d\n", getpid());
            sleep(1);
         }
    }

    else if(pid == 0){
        while(1){
            printf("This is a child print, pid = %d\n", getpid());
            sleep(1);
        }
    }
    return 0;
}
