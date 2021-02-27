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
    shmid = shmget(key, 1024 * 4, IPC_CREAT|0600);
    if(shmid == -1){
        printf("shmget error!\n");
        exit(-1);
    }
exit(0);
    shmaddr = shmat(shmid, 0, 0);
    printf("shmat ok!\n");

    strcpy(shmaddr, "LiYingxiang");

    sleep(5);
    shmdt(shmaddr);
    shmctl(shmid, IPC_RMID, 0);

    printf("quit\n");
    return 0;
}
