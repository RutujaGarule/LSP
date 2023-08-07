// Write a program which is used to create two threads
// First thread prints numbers from 1 to 500 and other thread print the number from 500 to 1

#include<stdio.h>
#include<pthread.h>

void * ThreadProc1(void * ptr)
{
   int i = 0;
   for(i = 1;i <= 500;i++)
   {
    printf("%d\n",i);
   }
    pthread_exit(NULL);
}

void * ThreadProc2(void * ptr)
{
    int i = 0;

   for(i = 500;i >= 1;i--)
   {
    printf("%d\n",i);
   }
    pthread_exit(NULL);
}

int main()
{
    pthread_t TID1,TID2;
    int Ret = 0;

    Ret = pthread_create(&TID1,NULL,ThreadProc1,NULL);
    if(Ret != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    printf("Thread is created successfully with TID : %d\n",TID1);

    Ret = pthread_create(&TID2,NULL,ThreadProc2,NULL);
    if(Ret != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    printf("Thread is created successfully with TID : %d\n",TID2);

    pthread_join(TID1,NULL);
    pthread_join(TID2,NULL);

    printf("End of main\n");

    return 0;
}