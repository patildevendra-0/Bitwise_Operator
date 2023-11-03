#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdlib.h> 

#define BLOCKSIZE 512
typedef long int LINT;

// Mutexes to protect access to the file descriptors
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex3 = PTHREAD_MUTEX_INITIALIZER;

void *ThreadProc1(void *ptr)
{
    int iCount = 0;
    char Buffer[BLOCKSIZE];
    int FileId = *(int *)ptr;
    int iCnt = 0;

    int iRet;
    while ((iRet = read(FileId, Buffer, sizeof(Buffer))) != 0)
    {
        for (iCnt = 0; iCnt < iRet; iCnt++)
        {
            if (Buffer[iCnt] >= 'a' && Buffer[iCnt] <= 'z')
            {
                iCount++;
            }
        }
    }

    pthread_mutex_lock(&mutex1);
    pthread_exit((void *)(LINT)iCount);
}

void *ThreadProc2(void *ptr)
{
    int iCount = 0;
    char Buffer[BLOCKSIZE];
    int FileId = *(int *)ptr;
    int iCnt = 0;

    int iRet;
    while ((iRet = read(FileId, Buffer, sizeof(Buffer))) != 0)
    {
        for (iCnt = 0; iCnt < iRet; iCnt++)
        {
            if (Buffer[iCnt] >= 'A' && Buffer[iCnt] <= 'Z')
            {
                iCount++;
            }
        }
    }

    pthread_mutex_lock(&mutex2);
    pthread_exit((void *)(LINT)iCount);
}

void *ThreadProc3(void *ptr)
{
    int iCount = 0;
    char Buffer[BLOCKSIZE];
    int FileId = *(int *)ptr;
    int iCnt = 0;

    int iRet;
    while ((iRet = read(FileId, Buffer, sizeof(Buffer))) != 0)
    {
        for (iCnt = 0; iCnt < iRet; iCnt++)
        {
            if (Buffer[iCnt] >= '0' && Buffer[iCnt] <= '9')
            {
                iCount++;
            }
        }
    }

    pthread_mutex_lock(&mutex3);
    pthread_exit((void *)(LINT)iCount);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("INSUFFICIENT ARGUMENTS...\n");
        return -1;
    }

    int Fd1 = open(argv[1], O_RDONLY);
    if (Fd1 == -1)
    {
        perror("UNABLE TO OPEN FILE");
        return -1;
    }

    int Fd2 = open(argv[1], O_RDONLY);
    if (Fd2 == -1)
    {
        perror("UNABLE TO OPEN FILE");
        close(Fd1);
        return -1;
    }

    int Fd3 = open(argv[1], O_RDONLY);
    if (Fd3 == -1)
    {
        perror("UNABLE TO OPEN FILE");
        close(Fd1);
        close(Fd2);
        return -1;
    }

    // Initialize mutexes
    pthread_mutex_init(&mutex1, NULL);
    pthread_mutex_init(&mutex2, NULL);
    pthread_mutex_init(&mutex3, NULL);

    pthread_t TID1, TID2, TID3;

    int iRet = pthread_create(&TID1, NULL, ThreadProc1, &Fd1);
    if (iRet != 0)
    {
        perror("UNABLE TO CREATE THREAD");
        close(Fd1);
        close(Fd2);
        close(Fd3);
        return -1;
    }

    iRet = pthread_create(&TID2, NULL, ThreadProc2, &Fd2);
    if (iRet != 0)
    {
        perror("UNABLE TO CREATE THREAD");
        close(Fd1);
        close(Fd2);
        close(Fd3);
        return -1;
    }

    iRet = pthread_create(&TID3, NULL, ThreadProc3, &Fd3);
    if (iRet != 0)
    {
        perror("UNABLE TO CREATE THREAD");
        close(Fd1);
        close(Fd2);
        close(Fd3);
        return -1;
    }

    // Join threads to retrieve their results
    int iret1, iret2, iret3 = 0;

    iRet = pthread_join(TID1, (void **)&iret1);
    if (iRet != 0)
    {
        perror("ERROR IN THREAD JOIN");
    }

    pthread_mutex_unlock(&mutex1);

    iRet = pthread_join(TID2, (void **)&iret2);
    if (iRet != 0)
    {
        perror("ERROR IN THREAD JOIN");
    }

    pthread_mutex_unlock(&mutex2);

    iRet = pthread_join(TID3, (void **)&iret3);
    if (iRet != 0)
    {
        perror("ERROR IN THREAD JOIN");
    }

    pthread_mutex_unlock(&mutex3);

    printf("SMALL LETTER COUNT FROM FILE - %s IS : %d\n", argv[1], iret1);
    printf("CAPITAL LETTER COUNT FROM FILE - %s IS : %d\n", argv[1], iret2);
    printf("DIGITS COUNT FROM FILE - %s IS : %d\n", argv[1], iret3);

    // Close the file descriptors
    close(Fd1);
    close(Fd2);
    close(Fd3);

    // Destroy the mutexes
    pthread_mutex_destroy(&mutex1);
    pthread_mutex_destroy(&mutex2);
    pthread_mutex_destroy(&mutex3);

    return 0;
}
