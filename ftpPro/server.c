








#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int get_cmd_type(char * cmd)
{
    if(!strcmp("ls", cmd))          return LS;
    if(!strcmp("quit", cmd))        return QUIT;
    if(!strcmp("pwd", cmd))         return PWD;
    if(strstr(cmd, "cd") != NULL)   return CD;
    if(strstr(cmd, "get") != NULL)  return GET;
    if(strstr(cmd, "put") != NULL)  return PUT;

    return 100;
}
char * getDesDir(char * cmsg)
{
    char * p = NULL;
    p = strtok(cmsg, " ");
    p = strtok(NULL, " ");
    return p;
}
void msg_handler(struct Msg msg, int fd)
{
    char dataBuf[10000] = {0};
    char * file = NULL;
    int fdfile;

    printf("cmd :%s\n", msg.cmd);
    int ret = get_cmd_type(msg.cmd);
    printf("ret = %d\n", ret);

    switch(ret){
        case LS:
        case PWD:
            msg.type = 0;
            FILE * r = popen(msg.cmd, "r");
            fread(msg.cmd, sizeof(msg), 1, r);
            write(fd, &msg, sizeof(msg));

            break;
        case CD:
            msg.type = 1;
            char * dir = getDesDir(msg.cmd);
            printf("dir:%s\n", dir);
            chdir(dir);
            break;
        case GET:
            file = getDesDir(msg.cmd);
            if(access(file, F_OK) == -1){
                strcpy(msg.cmd, "No this file!");
                write(fd, &msg, sizeof(msg));
            }else{
                msg.type = DOFILE;

                fdfile = open(file, O_RDWR);
                read(fdfile, dataBuf, sizeof(dataBuf));
                close(fdfile);

                strcpy(msg.cmd, dataBuf);
                write(fd, &msg, sizeof(msg));

            }
            break;

        case PUT:
            fdfile = open(getDesDir(msg.cmd), O_RDWR | O_CREAT, 0666);
            write(fdfile, msg.secondBuf, strlen(msg.secondBuf));
            close(fdfile);

            break;

        case QUIT:
            printf("client quit!\n");
            exit(-1);
    }
}
//int inet_aton(const char *cp, struct in_addr *inp);
int main(int argc, char **argv)
{
    if(argc != 3){
        printf("params number are not true!\n");
        exit(-1);
    }
    int s_fd;
    int c_fd;
    int n_read;
    struct Msg msg;
    //struct Msg msg;
    char readBuf[128] = {0};
    //struct

    //int socket(int domain, int type, int protocol);
    s_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(s_fd == -1){
        perror("socket");
        exit(-1);
    }
    printf("socket success!\n");

    //int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
    //struct  sockaddr_in {
    //    short  int  sin_family;                      /* Address family */
    //    unsigned  short  int  sin_port;       /* Port number */
    //    struct  in_addr  sin_addr;              /* Internet address */
    //    unsigned  char  sin_zero[8];         /* Same size as struct sockaddr */
    //};

    struct sockaddr_in s_addr;
    struct sockaddr_in c_addr;
    int clen = sizeof(struct sockaddr_in);
    memset(&s_addr, 0, clen);
    memset(&c_addr, 0, clen);
    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons(atoi(argv[2]));
    inet_aton(argv[1], &s_addr.sin_addr);

    int bind_ret = bind(s_fd, (struct sockaddr *)&s_addr, clen);
    if(bind_ret == -1){
        perror("bind");
        exit(-1);
    }

    //int listen(int sockfd, int backlog);
    int listen_ret = listen(s_fd, 10);

    if(listen_ret == -1){
        perror("listen");
        exit(-1);
    }
    //int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
    while(1){
        c_fd = accept(s_fd, (struct sockaddr *)&c_addr, &clen);
        if(c_fd == -1){
            perror("connect failed!");
            exit(-1);
        }
        printf("get connnect : %s\n", inet_ntoa(c_addr.sin_addr));

        if(fork() == 0){

            while(1){
                memset(msg.cmd, 0, sizeof(msg.cmd));
                n_read = read(c_fd, &msg, sizeof(msg));
                if(n_read == 0){
                    printf("client out\n");
                    break;
                }else if(n_read > 0){
                    msg_handler(msg, c_fd);
                }
            }
        }

    }
    close(c_fd);
    close(s_fd);
    return 0;
}
