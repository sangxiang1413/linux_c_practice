#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
int g_data = 0;
//int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);

pthread_mutex_t mutex;
void * func1(void *arg)
{
    pthread_mutex_lock(&mutex);
    for(int i = 0; i < 5; i++){
        printf("t1:%ld thread was created!\n",(unsigned long)pthread_self());
        printf("t1:param is %d\n", *((int *)arg));
        sleep(1);
    }
    pthread_mutex_unlock(&mutex);
}

void * func2(void *arg)
{
    pthread_mutex_lock(&mutex);
    printf("t2:%ld thread was created!\n",(unsigned long)pthread_self());
    printf("t2:param is %d\n", *((int *)arg));
    pthread_mutex_unlock(&mutex);
}

void * func3(void *arg)
{
    pthread_mutex_lock(&mutex);
    printf("t3:%ld thread was created!\n",(unsigned long)pthread_self());
    printf("t3:param is %d\n", *((int *)arg));
    pthread_mutex_unlock(&mutex);
}
int main()
{
    int ret;
    int param= 100;
    pthread_t t1;
    pthread_t t2;
    pthread_t t3;
    pthread_mutex_init(&mutex, NULL);
    ret = pthread_create(&t1, NULL, func1, (void *)&param);
    if(ret == 0){
        printf("create t1 success!\n");
    }

    ret = pthread_create(&t2, NULL, func2, (void *)&param);
    if(ret == 0){
        printf("create t2 success!\n");
    }
    ret = pthread_create(&t3, NULL, func3, (void *)&param);
    if(ret == 0){
        printf("create t2 success!\n");
    }

    printf("main : %ld\n", (unsigned long)pthread_self());
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    pthread_mutex_destroy(&mutex);
    return 0;
}
