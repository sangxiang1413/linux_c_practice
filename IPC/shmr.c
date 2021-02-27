#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//int shmget(key_t key, size_t size, int shmflg);

int main()
{
    key_t key;
    char * shmaddr;
    key = ftok(".", 1);
    int shmid;
    shmid = shmget(key, 1024 * 4, 0);
    if(shmid == -1){
        printf("shmget error!\n");
        exit(-1);
    }

    shmaddr = shmat(shmid, 0, 0);
    printf("shmat ok!\n");

    printf("data :%s\n", shmaddr);

    shmdt(shmaddr);

    printf("quit\n");
    return 0;
}
