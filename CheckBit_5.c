
#include<stdio.h>
#include<stdbool.h>
typedef unsigned int UINT;

/*
    `8/7/2`

    0000 0000 0000 0000 0000 0000 1100 0010
     0    0    0    0     0    0    C    2
     0X000000C2
*/

bool Check_BIT(UINT iNo)
{
    UINT iMask = 0X000000C2;
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
        printf(" 8,7,2 BIT IS ON\n");
    }
    else
    {
        printf(" 8,7,2 BIT IS OFF\n");
    }

    return 0;
}