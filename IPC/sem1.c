#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <unistd.h>
//int semget(key_t key, int nsems, int semflg);
//int semctl(int semid, int semnum, int cmd, ...);#include <sys/types.h>
int semop(int semid, struct sembuf *sops, size_t nsops);

union semun{
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO
   (Linux-specific) */
};
void pGetKey(int id)
{
    struct sembuf set;
    set.sem_num = 0;
    set.sem_op = -1;
    set.sem_flg = SEM_UNDO;
    semop(id, &set, 1);
    printf("gekey\n");
}

void vPutKeyBack(int id)
{
    struct sembuf set;
    set.sem_num = 0;
    set.sem_op = 1;
    set.sem_flg = SEM_UNDO;
    semop(id, &set, 1);
    printf("put back the key\n");
}
int main()
{
     union semun semInit;
     semInit.val = 0;
     key_t key = ftok(".", 1);
     int semId = semget(key, 1, IPC_CREAT|0666);
     semctl(semId, 0, SETVAL, semInit);

    int pid = fork();
    if(pid > 0){
        //nasuo
        pGetKey(semId);
        printf("This is a father!\n");
        //fangsuoi
        vPutKeyBack(semId);
    }else if(pid == 0){

        printf("This is a child!\n");
        vPutKeyBack(semId);
    }else{
        printf("fork error!\n");
    }

    return 0;
}
