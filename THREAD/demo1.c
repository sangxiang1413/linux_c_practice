#include <stdio.h>
#include <pthread.h>


//int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);

void * func1(void *arg)
{
    printf("%ld thread was created!\n",(unsigned long)pthread_self());
    printf("param is %d\n", *((int *)arg));
}
int main()
{
    int ret;
    int param = 100;
    pthread_t t1;

    ret = pthread_create(&t1, NULL, func1, (void *)&param);
    if(ret == 0){
        printf("create t1 success!\n");
        printf("main : %ld\n", (unsigned long)pthread_self());
    }else{
        printf("create t1 error!\n");
        printf("main : %ld\n", (unsigned long)pthread_self());
    }

    //while(1);
    pthread_join(t1, NULL);
    return 0;
}
