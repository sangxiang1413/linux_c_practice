#include <stdio.h>
#include <string.h>

int main()
{
    FILE * fp;
    char * str = "Hello world!";
    fp = fopen("./test.txt", "w+");
    int len = strlen(str);
    for (int i = 0; i < len; i++){
        fputc(*str, fp);
        str++;
    }
    fclose(fp);

    return 0;
}
