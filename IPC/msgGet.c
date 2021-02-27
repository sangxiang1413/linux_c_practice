#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <sys/ipc.h>
//int msgget(key_t key, int msgflg);

//ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg);

//struct msgbuf {
//    long mtype;       /* message type, must be > 0 */
//    char mtext[1];    /* message data */
//};


//key_t ftok(const char *pathname, int proj_id);

struct msgbuf
{
    long mtype;       /* message type, must be > 0 */
    char mtext[128];    /* message data */
};


int main()
{
    struct msgbuf readBuf;
    struct msgbuf sendBuf = {988, "receive from send over"};
    int msgId = msgget(0x1234, IPC_CREAT|0777);
    if(msgId == -1){
        printf("get que failuer\n");
    }
    key_t key;
    key = ftok(".", 'z');
    printf("key = %x\n", key);
    msgrcv(msgId, &readBuf, sizeof(readBuf.mtext), 888, 0);
    printf("read from que:%s\n", readBuf.mtext);
    msgsnd(msgId, &sendBuf, strlen(sendBuf.mtext), 0);
    msgctl(msgId, IPC_RMID, NULL);
    return 0;
}
