
#include<stdio.h>
#include<stdbool.h>
typedef unsigned int UINT;

/*
    `21/12/8/3`

    0000 0000 0001 0000 0000 1000 1000 0100
     0    0    1    0     0    8    8    4
     0X00100884
*/

bool Check_BIT(UINT iNo)
{
    UINT iMask = 0X00100884;
    UINT iResult = 0;

    iResult = iMask & iNo;
    if(iMask == iResult)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    UINT iNo = 0;
    bool bRet = false;

    printf("ENTER THE NUMBER :\n");
    scanf("%d",&iNo);

    bRet = Check_BIT(iNo);
    if(bRet == true)
    {
        printf(" 21/12/8/3 BIT IS ON\n");
    }
    else
    {
        printf(" 21/12/8/3 BIT IS OFF\n");
    }

    return 0;
}