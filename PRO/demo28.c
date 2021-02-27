#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>


int main()
{
    pid_t pid;
    int data = 10;
    while(1){
        printf("Please input a data:\n");
        scanf("%d", &data);

        if(data == 0){
            pid = fork();
            if(pid == 0){
                //execl("./changedata", "changedata", "config.txt", NULL);
                system("./changedata config.txt");
                exit(0);
            }

        }
        else{
            printf("Wait,do nothing.\n");
        }
    }


    return 0;
}
