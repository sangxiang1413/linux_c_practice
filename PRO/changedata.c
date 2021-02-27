#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    int fdSrc;
    if (argc != 2){
        printf("params error!\n");
        exit(-1);
    }
    fdSrc = open(argv[1], O_RDWR );
    // printf("fdSrc = %d\n", fdSrc);
    int size = lseek(fdSrc, 0, SEEK_END);
    lseek(fdSrc, 0, SEEK_SET);
    char * readBuf = (char *)malloc(sizeof(char) * size + 8);
    //printf("readBuf = %p\n", readBuf);
    if(readBuf == NULL){
        printf("Failed to allocate space!\n");
        exit(-1);
    }
    int n_read = read(fdSrc, readBuf, size);
    char * p = strstr(readBuf, "LENG=");
    //printf("p = %p\n", p);
    if(p == NULL){
        printf("not found!\n\n");
        exit(-1);
    }
    p = p + strlen("LENG=");
    *p = '5';
    lseek(fdSrc, 0, SEEK_SET);
    int n_write = write(fdSrc, readBuf, strlen(readBuf));

    close(fdSrc);

    return 0;
}

