#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    pid_t pid;
    int data = 10;
    while(1){
        printf("Please input a data:\n");
        scanf("%d", &data);

        if(data == 1){
            pid = fork();

            if(pid > 0){
                //printf("This is a father print, pid = %d\n", getpid());
            }
            else if(pid == 0){
                //printf("This is a child print, child pid = %d\n", getpid());
                //data = data + 100;
                while(1){
                    printf("Do net request pid = %d\n", getpid());
                    sleep(3);
                }
            }
        }
        else{
            printf("Wait do nothing.\n");
        }
    }


    return 0;
}
