#include<stdio.h>

typedef unsigned int UINT;

/*
    0000 0000 0000 0011 0100 1010 0010 0101
    1111 1111 1111 1111 1111 1111 1111 1111

    0XFFFFFFFF;
*/

int TOGGLE_BIT(UINT iNo)
{
    UINT iMask = 0XFFFFFFFF;
    UINT iResult = 0;

    iResult = iMask ^ iNo;
    return iResult;
}

int main()
{
    UINT iNo = 0;
    UINT iRet = 0;

    printf("ENTER THE NUMBER: \n");
    scanf("%d",&iNo);

    iRet = TOGGLE_BIT(iNo);
    printf("UPDATED NUMBER: %d\n",iRet);

    return 0;
}