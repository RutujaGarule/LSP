// Write a program which creates two threads by using pthread API,
// one thread count number of capital characters from demo.txt file and other thread will count number of small characters from same file


#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<fcntl.h>

#define MAXBUFFER 1024

void * ThreadProc1(void * ptr)
{
    int fd = *(int *) ptr;
    int Ret = 0, i = 0;
    int Small = 0;
    char Buff[MAXBUFFER] = {'\0'};

    lseek(fd,0,SEEK_SET);

    while((Ret = read(fd,Buff,sizeof(Buff))) != 0)
    {
        for(i = 0; i < Ret;i++)
        {
            if((Buff[i] >= 'a') && (Buff[i] <= 'z'))
            {
                Small++;
            }
        }
    }
    printf("Number of small characters are : %d\n",Small);

    pthread_exit(Small);
}

void * ThreadProc2(void * ptr)
{
    int fd = *(int *) ptr;
    int Ret = 0;
    int i = 0;
    int Capital = 0;
    char Buff[MAXBUFFER] = {'\0'};

    lseek(fd,0,SEEK_SET);

    while((Ret = read(fd,Buff,sizeof(Buff))) != 0)
    {
        for(i = 0; i < Ret; i++)
        {
            if((Buff[i] >= 'A') && (Buff[i] <= 'Z'))
            {
                Capital++;
            }
        }
    }

    printf("Number of capital characters are : %d\n",Capital);

    pthread_exit(Capital);
}

int main()
{
    pthread_t TID1,TID2;
    int Ret = 0;
    int fd = 0;
    int Small = 0;
    int Capital = 0;

    fd = open("Demo.txt",O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open the file\n");
        return -1;
    }

    Ret = pthread_create(&TID1,NULL,ThreadProc1,&fd);
    if(Ret != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }
    printf("Thread 1 is created with TID : %lu\n",TID1);

    Ret = pthread_create(&TID2,NULL,ThreadProc2,&fd);
    if(Ret != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }
    printf("Thread 2 is created with TID : %lu\n",TID2);

    pthread_join(TID1,&Small);
    pthread_join(TID2,&Capital);

    printf("Number of small characters are : %d\n",Small);
    printf("Number of capital characters are : %d\n",Capital);

    close(fd);

    printf("End of main thread\n");

    pthread_exit(NULL);

    return 0;
}