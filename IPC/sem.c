#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <unistd.h>

//int semget(key_t key, int nsems, int semflg);
//int semctl(int semid, int semnum, int cmd, ...);
union semun{
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO
   (Linux-specific) */
};

int main()
{
    union semun semInit;
    semInit.val = 1;
    key_t key = ftok(".", 1);
    int semId = semget(key, 1, IPC_CREAT|0666);
    semctl(semId, 0, SETVAL, semInit);

    int pid = fork();
    if(pid > 0){
        //nasuo
        printf("This is a father!\n");
        //fangsuo

    }else{

        printf("This is a child!\n");
    }

    return 0;
}
