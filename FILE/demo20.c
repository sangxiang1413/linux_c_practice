#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Test
{
    int a;
    char c;
};
int main()
{
    FILE * fp;
    struct Test data1 = {100, 'a'};
    struct Test data2;
    fp = fopen("./file1", "w+");
    if(fp == NULL){
        printf("Error!\n");
        exit(-1);
    }
    int n_write = fwrite(&data1, sizeof(struct Test), 1, fp);

    fseek(fp, 0, SEEK_SET);
    int n_read = fread(&data2, sizeof(struct Test), 1, fp);

    printf("read data1.a :%d\nread data1.c :%c\n", data2.a, data2.c);
    fclose(fp);

    return 0;
}

