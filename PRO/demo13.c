#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    pid_t pid;
    int cnt = 0;
    pid = vfork();
    if(pid > 0){
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
            if(cnt == 3){
                //break;
                exit(0);
            }
        }
    }
    return 0;
}
