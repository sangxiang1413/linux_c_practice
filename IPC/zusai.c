#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


int main()
{
    int fd[2];
    int pid;
    char readBuf[128];
    if(pipe(fd) == -1){
        printf("Create pipe failed!\n");
        exit(0);
    }
    pid = fork();
    if(pid < 0){
        printf("Create child failed!\n");
    }
    else if(pid > 0){
        sleep(3);
        printf("This is father!\n");
        close(fd[0]);
        write(fd[1], "hello from father", strlen("hello from father"));
        wait(NULL);
    }else{
        printf("This is child!\n");
        close(fd[1]);
        read(fd[0], readBuf, 128);
        printf("read from father : %s\n", readBuf);
        exit(0);
    }


    return 0;
}
