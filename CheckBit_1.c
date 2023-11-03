#include<stdio.h>
#include<stdbool.h>
typedef unsigned int UINT;

///// 4th bit check
/*
    0000 0000 0000 0000 0000 0000 0000 1000
      0    0    0    0    0    0    0    8
        0X00000008;
*/

bool CHECK_BIT(UINT iNo)
{
    UINT iMask = 0X00000008;
    UINT iResult = 0;

    iResult = iNo & iMask;

    if(iResult == iMask)
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
    bool bRet = false;
    UINT iNo = 0;

    printf("Enter the Number :\n");
    scanf("%d",&iNo);

    bRet = CHECK_BIT(iNo);
    if(bRet == true)
    {
        printf("4th Bit is ON\n");
    }
    else
    {
        printf("4th Bit is OFF\n");
    }


    return 0;
}

/*
    ex iNo  = 10;

    0000 0000 0000 0000 0000 0000 0000 1010
    &
    0000 0000 0000 0000 0000 0000 0000 1000
    ------------------------------------------
    0000 0000 0000 0000 0000 0000 0000 1000

*/