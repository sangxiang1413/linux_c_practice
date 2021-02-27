#include <stdio.h>

struct Test{
    int a;
    char b;
    int c;
    long d;
    char e;
};
int main()
{
    printf("Size of Struct is %ld byte\n", sizeof(struct Test));

    return 0;
}
