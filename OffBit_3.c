#include<stdio.h>

typedef unsigned int UINT;

/*
    0000 0000 0000 0000 0100 0011 0101 1000
    1111 1111 1111 1111 1111 1111 1010 1111
    F     F    F    F     F    F   A    F
    0XFFFFFFAF
*/

int OFF_BIT(UINT iNo)
{
    UINT iMask = 0XFFFFFFAF;
    UINT iAns = 0;

    iAns = iMask & iNo;
    return iAns;
}

int main()
{
    UINT iNo = 0;
    UINT iRet = 0;

    printf("ENTER THE NUMBER :");
    scanf("%d",&iNo);

    iRet = OFF_BIT(iNo);
    printf("UPDATED NUMBER: %d\n",iRet);

    return 0;
}