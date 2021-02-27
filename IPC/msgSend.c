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
struct msgbuf
{
    long mtype;       /* message type, must be > 0 */
    char mtext[128];    /* message data */
};


int main()
{
    struct msgbuf sendBuf = {888, "this is message from quen"};
    struct msgbuf readBuf;
    int msgId = msgget(0x1234, IPC_CREAT|0777);
    if(msgId == -1){
        printf("get que failuer\n");
    }
    key_t key;
    key = ftok(".", 'z');
    printf("key = %x\n", key);
    msgsnd(msgId, &sendBuf, strlen(sendBuf.mtext), 0);
    printf("send over!\n");
    msgrcv(msgId, &readBuf, sizeof(readBuf.mtext), 988, 0);
    printf("return from get:%s\n", readBuf.mtext);
    //msgctl(msgId, IPC_RMID, NULL);
    return 0;
}
