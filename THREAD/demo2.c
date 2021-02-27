#include <stdio.h>
#include <pthread.h>


//int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
//int pthread_join(pthread_t thread, void **retval);
//void pthread_exit(void *retval);
void * func1(void *arg)
{
    static int ret = 10;
    printf("%ld thread was created!\n",(unsigned long)pthread_self());
    printf("param is %d\n", *((int *)arg));
    pthread_exit((void *)&ret);
}
int main()
{
    int ret;
    int param = 100;
    pthread_t t1;
    int *pret = NULL;

    ret = pthread_create(&t1, NULL, func1, (void *)&param);
    if(ret == 0){
        printf("main :create t1 success!\n");
    }
    printf("main : %ld\n", (unsigned long)pthread_self());
    //while(1);
    pthread_join(t1, (void **)&pret);
    printf("main : t1 quit!\n");
    return 0;
}
