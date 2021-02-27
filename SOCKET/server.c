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
#include <sys/wait.h>
//int socket(int domain, int type, int protocol);
//int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
//int inet_aton(const char *cp, struct in_addr *inp);
//int listen(int sockfd, int backlog);
int main(int argc, char **argv)
{
    if(argc != 3){
        printf("param number is not ture!\n");
        exit(-1);
    }
    int s_fd;
    int c_fd;
    int n_read;
    int mark = 0;
    //char * str = "hello from the server";
    char msg[128] = {0};
    char readBuf[128] = {0};
    memset(readBuf, 0, 128);
    memset(msg, 0, 128);
    int clang = (int)sizeof(struct sockaddr_in);
    //1.socket
    s_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(s_fd == -1){
        perror("socket");
        exit(-1);
    }
    struct sockaddr_in s_addr;
    struct sockaddr_in c_addr;
    memset(&s_addr, 0, sizeof(struct sockaddr_in));
    memset(&c_addr, 0, sizeof(struct sockaddr_in));
    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons(atoi(argv[2]));
    inet_aton(argv[1], &s_addr.sin_addr);
    //2.bind
    bind(s_fd, (struct sockaddr *)&s_addr, (int)sizeof(struct sockaddr_in));

    //3.listen
    listen(s_fd, 10);
    while(1){
    //4.accept
    //int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
        c_fd = accept(s_fd, (struct sockaddr *)&c_addr, &clang);

        if(c_fd == -1){
            perror("connect failed!");
        }
        mark++;
        printf("get connect: %s\n", inet_ntoa(c_addr.sin_addr));
        if(fork() == 0){

            if(fork() == 0){
                while(1){
                    memset(msg, 0, sizeof(msg));
                    sprintf(msg, "welcom to No.%d client!\n", mark);
                    write(c_fd, msg, strlen(msg));
                    sleep(3);

                }
            }


            while(1){
                //    wait(NULL);
                //5.read
                memset(readBuf, 0, sizeof(readBuf));
                n_read = read(c_fd, readBuf, 128);
                if(n_read == -1){
                    perror("read failed");
                }else{
                    printf("read %d byte, %s\n", n_read, readBuf);
                }
            }
            break;
        }
            //6.write
        //break;
    }
    return 0;
}

