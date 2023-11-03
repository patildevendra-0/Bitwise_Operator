/*
    START
        Accept File from user using command line
        open that file----------------------------using open system call 
        create three separte threads and perform task --------------using pthread library
    END
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Application Name :  multithreading application
//  Description :       to demonstrate the use of multithreading to efficiently count different character types in a file
//  Input :             .txt file
//  Output :            Count of Capital letter , small letter, digits
//  Author :            Devendra Patil
//  Date :              03/11/2023
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////



#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdlib.h> 

#define BLOCKSIZE 512     // Buffer Size 
typedef long int LINT;    

pthread_mutex_t lock1;
pthread_mutex_t lock2;
pthread_mutex_t lock3;

/////////////////////////////////////////////////////////////////////////////
//// Thread -1     this callback function count the small letter in file
/////////////////////////////////////////////////////////////////////////////
void *ThreadProc1(void *ptr)          
{
    pthread_mutex_lock(&lock1);
    int iCount = 0;
    char Buffer[BLOCKSIZE];
    int FileId = *(int *)ptr;
    int iCnt = 0;
    int iRet = 0;

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
    pthread_mutex_unlock(&lock1);
    pthread_exit((void *)(LINT)iCount);
}

/////////////////////////////////////////////////////////////////////////////
//// Thread -2     this callback function count the Capital letter in file
/////////////////////////////////////////////////////////////////////////////
void *ThreadProc2(void *ptr)                 
{
    pthread_mutex_lock(&lock2);

    int iCount = 0;
    char Buffer[BLOCKSIZE];
    int FileId = *(int *)ptr;
    int iCnt = 0;
    int iRet = 0;

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
    pthread_mutex_unlock(&lock2);
    pthread_exit((void *)(LINT)iCount);
}

/////////////////////////////////////////////////////////////////////////////
//// Thread -3     this callback function count the Digits in file
/////////////////////////////////////////////////////////////////////////////
void *ThreadProc3(void *ptr)                       
{
    pthread_mutex_lock(&lock3);

    int iCount = 0;
    char Buffer[BLOCKSIZE];
    int FileId = *(int *)ptr;
    int iCnt = 0;
    int iRet = 0;

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
    pthread_mutex_unlock(&lock3);
    pthread_exit((void *)(LINT)iCount);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//  Entry point of the application
//////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
    pthread_mutex_init(&lock1,NULL);
    pthread_mutex_init(&lock2,NULL);
    pthread_mutex_init(&lock3,NULL);


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
        close(Fd1);                                    // Close the previously opened file descriptor
        return -1;
    }

    int Fd3 = open(argv[1], O_RDONLY);
    if (Fd3 == -1)
    {
        perror("UNABLE TO OPEN FILE");
        close(Fd2);                                    // Close the previously opened file descriptor
        return -1;
    }

    pthread_t TID1, TID2, TID3;

    int iRet = pthread_create(&TID1, NULL, ThreadProc1, &Fd1);
    if (iRet != 0)
    {
        perror("UNABLE TO CREATE THREAD");
        close(Fd1);
        close(Fd2);
        return -1;
    }

    iRet = pthread_create(&TID2, NULL, ThreadProc2, &Fd2);
    if (iRet != 0)
    {
        perror("UNABLE TO CREATE THREAD");
        close(Fd1);
        close(Fd2);
        return -1;
    }

    iRet = pthread_create(&TID3, NULL, ThreadProc3, &Fd3);
    if (iRet != 0)
    {
        perror("UNABLE TO CREATE THREAD");
        close(Fd1);
        close(Fd2);
        return -1;
    }
    
    // Join threads to retrieve their results
    int iret1, iret2, iret3 = 0;

    iRet = pthread_join(TID1, (void **)&iret1);
    if (iRet != 0)
    {
        perror("ERROR IN THREAD JOIN");
    }

    iRet = pthread_join(TID2, (void **)&iret2);
    if (iRet != 0)
    {
        perror("ERROR IN THREAD JOIN");
    }

    iRet = pthread_join(TID3, (void **)&iret3);
    if (iRet != 0)
    {
        perror("ERROR IN THREAD JOIN");
    }

    printf("------------------------------------------------------------\n");
    printf("SMALL LETTER COUNT FROM FILE - %s IS : %d\n", argv[1], iret1);
    printf("CAPITAL LETTER COUNT FROM FILE - %s IS : %d\n", argv[1], iret2);
    printf("DIGITS COUNT FROM FILE - %s IS : %d\n", argv[1], iret3);
    printf("------------------------------------------------------------\n");


    // release system resources
    // Close the file descriptor
    close(Fd1);                                                              
    close(Fd2);
    close(Fd3);
    // Destroy the lock 
    pthread_mutex_destroy(&lock1);
    pthread_mutex_destroy(&lock2);
    pthread_mutex_destroy(&lock3);

    return 0;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////
//  Result
//  Input : Demo.txt   (any .txt file)
//  Output :    SMALL LETTER COUNT FROM FILE - demo.txt IS : 5
//              CAPITAL LETTER COUNT FROM FILE - demo.txt IS : 5
//              DIGITS COUNT FROM FILE - demo.txt IS : 5
//////////////////////////////////////////////////////////////////////////////////////////////////////////