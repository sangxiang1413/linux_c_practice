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
//int inet_aton(const char *cp, struct in_addr *inp);

char * getDir(char * cmd)
{
    char * p = NULL;
    p = strtok(cmd, " ");
    p = strtok(NULL, " ");
    return p;
}
int get_cmd_type(char * cmd)
{
    if(strstr(cmd, "lcd"))      return LCD;

    if(!strcmp("quit", cmd))    return QUIT;
    if(!strcmp("ls", cmd))      return LS;
    if(!strcmp("lls", cmd))     return LLS;
    if(!strcmp("pwd", cmd))     return PWD;

    if(strstr(cmd, "cd"))       return CD;
    if(strstr(cmd, "get"))      return GET;
    if(strstr(cmd, "put"))      return PUT;

    return -1;
  }
int cmd_handler(struct Msg msg, int fd)
{
    char * dir = NULL;
    char buf[32] = {0};
    int ret;
    int filefd;

    ret = get_cmd_type(msg.cmd);
    printf("ret = %d\n", ret);

    switch(ret){
        case LS:
        case CD:
        case PWD:
            msg.type = 0;
            write(fd, &msg, sizeof(msg));
            break;
        case GET:
            msg.type = 2;
            write(fd, &msg, sizeof(msg));
            break;
        case PUT:
            strcpy(buf, msg.cmd);
            dir = getDir(buf);

            if(access(dir, F_OK) == -1){
                printf("%s not exsit!\n", dir);
            }else{
                filefd = open(dir, O_RDWR);
                read(filefd, msg.secondBuf, sizeof(msg.secondBuf));
                close(filefd);

                write(fd, &msg, sizeof(msg));
            }
            break;
        case LLS:
            system("ls");
            break;
        case LCD:
            dir = getDir(msg.cmd);
            chdir(dir);
            break;
        case QUIT:
            strcpy(msg.cmd, "quit");
            write(fd, &msg, sizeof(msg));
            close(fd);
            exit(-1);

    }

    return ret;
}
void handler_server_message(int c_fd, struct Msg msg)
{
    int n_read;
    struct Msg msgget;
    int newfilefd;

    n_read = read(c_fd, &msgget, sizeof(msgget));

    if(n_read == 0){
        printf("server is out,quit\n");
        exit(-1);
    }
    else if(msgget.type == DOFILE){
        char * p = getDir(msg.cmd);
        newfilefd = open(p, O_RDWR | O_CREAT, 0666);
        write(newfilefd, msgget.cmd, strlen(msgget.cmd));
        putchar('>');
        fflush(stdout);
    }
    else{
        printf("................................\n");
        printf("\n%s\n", msgget.cmd);
        printf("................................\n");

        putchar('>');
        fflush(stdout);
    }

}
int main(int argc, char **argv)
{
    if(argc != 3){
        printf("params number are not true!\n");
        exit(-1);
    }
    int c_fd;
    FILE * fp = NULL;
    char readBuf[128];
    struct Msg msg;
    //struct

    //int socket(int domain, int type, int protocol);
    c_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(c_fd == -1){
        perror("socket");
        exit(-1);
    }
    printf("socket success!\n");

    struct sockaddr_in c_addr;
    int clen = sizeof(struct sockaddr_in);
    memset(&c_addr, 0, clen);
    c_addr.sin_family = AF_INET;
    c_addr.sin_port = htons(atoi(argv[2]));
    inet_aton(argv[1], &c_addr.sin_addr);

    //int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
    int connect_ret = connect(c_fd, (struct sockaddr *)&c_addr, clen);
    if(connect_ret == -1){
        perror("connect");
        exit(-1);
    }
    printf("connect server success!\n");
    int mark = 0;

    while(1){

        memset(msg.cmd, 0, sizeof(msg.cmd));
        gets(msg.cmd);

        int ret = cmd_handler(msg, c_fd);
        if(ret > IFGO){
            putchar('>');
            fflush(stdout);
            continue;
        }
        if(ret == -1){
            printf("command not \n");
            printf(">");
            fflush(stdout);
            continue;
        }
        handler_server_message(c_fd, msg);
    }


    return 0;
}
