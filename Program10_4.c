// Write a program which is used to create single thread and it accept one value from user and it return some value to the caller thread

#include<stdio.h>
#include<pthread.h>

void * ThreadProc(void * ptr)
{
    int i = *(int*) ptr;
    int Ret = 0;
    printf("Value from main thread is : %d\n",i);
    Ret = i + 10;
    pthread_exit(Ret);
}

int main()
{
    pthread_t TID;
    int Ret = 0;
    int Value = 11;
    int i = 0;

    Ret = pthread_create(&TID,NULL,ThreadProc,&Value);
    if(Ret != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    printf("Thread is created successfully with TID : %lu\n",TID);

    pthread_join(TID,&i);
    printf("Value received from thread is : %d\n",i);

    printf("End of main\n");


    return 0;
}

