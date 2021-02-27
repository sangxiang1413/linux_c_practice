#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
//#include <linux/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//int socket(int domain, int type, int protocol);
//int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
//int inet_aton(const char *cp, struct in_addr *inp);
//int listen(int sockfd, int backlog);
int main(int argc, char **argv)
{
    if(argc != 3){
        printf("params number is not true!\n");
        exit(-1);
    }
    int c_fd;
    //char * str = "message from the client";
    char msg[128] = {0};
    char readBuf[128] = {0};
    memset(readBuf, 0, 128);
    int n_read;
    //int clang = (int)sizeof(struct sockaddr_in);
    //1.socket
    c_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(c_fd == -1){
        perror("socket");
        exit(-1);
    }
    struct sockaddr_in c_addr;
    memset(&c_addr, 0, sizeof(struct sockaddr_in));
    c_addr.sin_family = AF_INET;
    c_addr.sin_port = htons(atoi(argv[2]));
    inet_aton(argv[1], &c_addr.sin_addr);

    //2.connect
    //int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
    if(connect(c_fd, (struct sockaddr *)&c_addr, sizeof(struct sockaddr)) == -1){
        perror("connect");
        exit(-1);
    }
    while(1){
        if(fork() == 0){
            while(1){


                //send
                memset(msg, 0, sizeof(msg));
                printf("input:");
                scanf("%s", msg);

                write(c_fd, msg, strlen(msg));
            }
        }
        while(1){

            //read
            memset(readBuf, 0, sizeof(readBuf));
            n_read = read(c_fd, readBuf, 128);
            if(n_read == -1){
                perror("read failed");
            }else{
                printf("get %d byte from srever :%s\n", n_read, readBuf);
            }
        }
    }
    return 0;
}
