#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
//int mkfifo(const char *pathname, mode_t mode);

int main()
{
    mkfifo("./file", 0600);

    return 0;
}

