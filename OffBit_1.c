
#include<stdio.h>
typedef unsigned int UINT;

/*
    off 9th bit
                             9th
    0000 0000 0000 0000 0000 0001 0010 1000
    1111 1111 1111 1111 1111 1110 1111 1111 
    0XFFFFFEFF
*/

int OFF_BIT(UINT iNo)
{
    UINT iMask = 0XFFFFFEFF;
    UINT iResult = 0;

    iResult = iMask & iNo;
    
    return iResult;
}

int main()
{
    UINT iNo = 0;
    UINT iRet = 0;
    printf("ENTER THE NUMBER :\n");
    scanf("%d",&iNo);

    iRet = OFF_BIT(iNo);
    printf("UPDATED NUMBER IS : %d\n",iRet);

    return 0;
}