#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>


int main()
{
    if(system("./changedata config.txt") == -1){
        printf("excl failed\n");
        perror("why");
    }
    printf("after excl\n");
    return 0;
}
