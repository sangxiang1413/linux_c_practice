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
    int fdDes;
    char * readBuf = NULL;
    if(argc != 3){
        printf("param error\n");
        exit(-1);
    }

    fdSrc = open(argv[1], O_RDWR);
    int size = lseek(fdSrc, 0, SEEK_END);
    lseek(fdSrc, 0, SEEK_SET);
    readBuf = (char *)malloc(sizeof(char) * size + 8);
    int n_read = read(fdSrc, readBuf, size);
    fdDes = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0600);
    int n_write = write(fdDes, readBuf, strlen(readBuf));

    close(fdSrc);
    close(fdDes);

    return 0;
}

