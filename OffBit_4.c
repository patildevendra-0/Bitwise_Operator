#include<stdio.h>

typedef unsigned int UINT;

/*  2/10/14

    0000 0000 0000 0000 0010 1010 0000 0110
    1111 1111 1111 1111 1101 1101 1111 1101
    F     F     F   F    D    D    F    D
    0XFFFFDDFD
*/

int OFF_BIT(UINT iNo)
{
    UINT iMask = 0XFFFFDDFD;
    UINT iAns = 0;

    iAns = iMask & iNo;
    return iAns;
}

int main()
{
    UINT iNo = 0;
    UINT iRet = 0;

    printf("ENTER THE NUMBER: \n");
    scanf("%d",&iNo);

    iRet = OFF_BIT(iNo);
    printf("UATED NUMBER: %d\n",iRet);

    return 0;
}