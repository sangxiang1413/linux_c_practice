#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>


int main()
{
    char ret[1024] = {0};

    system("ps");

    printf("ret = %s\n", ret);

    return 0;
}
