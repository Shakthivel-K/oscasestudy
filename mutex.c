//mutex
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
pthread_t tid[2];
int count;
pthread_mutex_t lock;
void *try(void *arg)
{
    pthread_mutex_lock (&lock);
    unsigned long i=0;
    count+=1;
    printf("Job %d started",count);
    for (int i=0;i<0xFFFFFFFF;i++);
    printf("Job %d finished",count);
    pthread_mutex_unlock(&lock);
    return NULL;
}
int main(void)
{
    int i=0;
    int er;
    if (pthread_mutex_init(&lock,NULL)!=0)
    {
        printf("\n mutex failed");
        return 1;
    }
    while (i<2)
    {
        er = pthread_create(&tid[i],NULL,try,NULL);
        if (er!=0)
        {
            printf("\n Thread cannot be created [%s]",strerror(er));
        }
        i++;
    }
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    pthread_mutex_destroy(&lock);
    return 0;
}