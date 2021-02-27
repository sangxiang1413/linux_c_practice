#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    FILE * fp;
    char * buf = "Hello World!";
    char * readBuf = (char *)malloc(sizeof(char) * 128);
    //FILE *fopen(const char *pathname, const char *mode);
    fp = fopen("./Li.txt", "w+");
    //size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
    fwrite(buf, sizeof(char), strlen(buf), fp);
    //fwrite(buf, sizof(char) * strlen(buf), 1, fp);
    //int fseek(FILE *stream, long offset, int whence);
    fseek(fp, 0, SEEK_SET);
    //size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
    fread(readBuf, sizeof(char), strlen(buf), fp);

    printf("read data : %s\n", readBuf);
    fclose(fp);

    return 0;
}
