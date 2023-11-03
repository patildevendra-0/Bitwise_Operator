#include<stdio.h>
typedef unsigned int UINT;

/*
    0000 0000 0000 0000 0000 1001 0100 0100
    1111 1111 1111 1111 1111 0111 1011 1111

     f    f    f    f     f    7    b    f
*/

int OFF_BIT(UINT iNo)
{
    UINT iMask = 0XFFFFF7BF;
    UINT iAns = 0;

    iAns = iMask & iNo;
    return iAns;
}

int main()
{
    UINT iNo = 0;
    UINT iRet = 0;

    printf("ENTER THE NUMBER :\n");
    scanf("%d",&iNo);

    iRet = OFF_BIT(iNo);
    printf("UPDATED NUMBER: %d\n",iRet);

    return 0;
}