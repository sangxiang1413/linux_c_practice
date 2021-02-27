#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
int g_data = 0;
//int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);

void * func1(void *arg)
{
    printf("t1:%ld thread was created!\n",(unsigned long)pthread_self());
    printf("t1:param is %d\n", *((int *)arg));
    while(1){
        printf("t1:%d\n", g_data++);
        sleep(1);
    }
}

void * func2(void *arg)
{
    printf("t2:%ld thread was created!\n",(unsigned long)pthread_self());
    printf("t2:param is %d\n", *((int *)arg));
    while(1){
        printf("t2:%d\n", g_data++);
        sleep(1);
    }
}

int main()
{
    int ret;
    int param= 100;
    pthread_t t1;
    pthread_t t2;
    ret = pthread_create(&t1, NULL, func1, (void *)&param);
    if(ret == 0){
        printf("create t1 success!\n");
        if(g_data == 3){
            pthread_exit(NULL);
        }
    }

    ret = pthread_create(&t2, NULL, func2, (void *)&param);
    if(ret == 0){
        printf("create t2 success!\n");
    }
    printf("main : %ld\n", (unsigned long)pthread_self());
    while(1){
        printf("main:%d\n", g_data++);
        sleep(1);
    }
    //while(1);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}
