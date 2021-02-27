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
    FILE * fp;
    fp = popen("ps", "r");

    int n_read = fread(ret, 1, 1024, fp);

    printf("read ret %d byte,ret = %s\n", n_read, ret);

    return 0;
}
