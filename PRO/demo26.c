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
                int fdSrc;
                char * readBuf = NULL;
                fdSrc = open("config.txt", O_RDWR);
                int size = lseek(fdSrc, 0, SEEK_END);
                lseek(fdSrc, 0, SEEK_SET);
                readBuf = (char *)malloc(sizeof(char) * size + 8);
                int n_read = read(fdSrc, readBuf, size);

                char * p = strstr(readBuf, "LENG=");
                if(p == NULL){
                    printf("not found\n");
                    exit(-1);
                }
                p = p + strlen("LENG=");
                *p = '5';
                lseek(fdSrc, 0, SEEK_SET);
                int n_write = write(fdSrc, readBuf, strlen(readBuf));
                close(fdSrc);
                exit(0);
            }

        }
        else{
            printf("Wait,do nothing.\n");
        }
    }


    return 0;
}
