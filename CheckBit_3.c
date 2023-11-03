#include<stdio.h>
#include<stdbool.h>
typedef unsigned int UINT;

///2 and 5 bit check

/*  
    0000 0000 0000 0000 0000 0000 0001 0010
     0    0    0    0    0    0     1    2
    0X00000012

    0000 0000 0000 0000 0000 0000 0000 0010   -  1     -  0X00000002
    0000 0000 0000 0000 0000 0000 0001 0000   -  2     -  0X00000010

*/

bool Check_BIT(UINT iNo)
{
    UINT iMask = 0X00000012;
    UINT iMask1 = 0X00000002;
    UINT iMask2 = 0X00000010;
    UINT iResult = 0;

    iResult = iMask & iNo;
    if(iResult == iMask)
    {
        return true;
    }
    else
    {
        iResult = iMask1 & iNo;
        if(iResult == iMask1)
        {
            printf("2 nd bit is ON \n");
        }
        else
        {
            printf("2 nd bit is OFF \n");
        }

        iResult = iMask2 & iNo;
        if(iResult == iMask2)
        {
            printf("5 th bit is ON \n");
        }
        else
        {
            printf("5 th bit is OFF \n");
        }

        return false;
    }
}

int main()
{   
    UINT iNo = 0;
    bool bRet = false;

    printf("ENTER THE NUMBER: \n");
    scanf("%d",&iNo);

    bRet = Check_BIT(iNo);
    if(bRet == true)
    {
        printf("2 AND 5 BIT IS ON \n");
    }
    else
    {
        printf("2 AND 5 BIT IS OFF \n");
    }


    return 0;
}