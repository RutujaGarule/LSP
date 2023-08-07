// Write a program which is used to predict the problem due to lack of synchronization 

#include<stdio.h>
#include<pthread.h>

int Counter = 0;

void * ThreadProc(void * ptr)
{
    int i = 0;
    Counter++;
    
    printf("Thread executed with counter : %d\n",Counter);
    for(i = 0;i < 0xFFFFFFFF;i++);
    printf("Thread completed with counter : %d\n",Counter);

     pthread_exit(NULL);
  
}


int main()
{
    pthread_t TID1,TID2;
    int Ret = 0;

    Ret = pthread_create(&TID1,NULL,ThreadProc,NULL);
    if(Ret != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }
    printf("First Thread created with TID : %lu\n",TID1);

    Ret = pthread_create(&TID2,NULL,ThreadProc,NULL);
    if(Ret != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }
    printf("Second Thread created with TID : %lu\n",TID2);

    pthread_join(TID1,NULL);
    pthread_join(TID2,NULL);

    printf("End of main\n");

    pthread_exit(NULL);

    return 0;
}