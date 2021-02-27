#include <stdio.h>
#include <string.h>

int main()
{
    FILE * fp;
    fp = fopen("./test.txt", "w+");

    fputc('a', fp);
    fclose(fp);

    return 0;
}
