#include <stdio.h>

int main()
{
    FILE * fp = fopen("./test.txt", "r");
    char c;
    while(!feof(fp)){ //nonzero  is returned  until read to the end of file
        c = fgetc(fp);
        printf("%c", c);
    }
    putchar('\n');
    fclose(fp);
    return 0;;
}
