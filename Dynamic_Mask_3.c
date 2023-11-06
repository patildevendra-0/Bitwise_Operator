#include<stdio.h>
typedef unsigned int UINT;

/*
    0000 0000 0000 0000 0000 1010 0110 0011
    1111 1111 1111 1111 1111 0101 1111 1111
*/

int OFF_BIT(UINT iMask,int iNo)
{
    UINT iAns = iMask & iNo;
    return iAns;
}

int DYNAMIC_MASK(UINT iPos_1 , UINT iPos_2)
{
    UINT iMask_1 = 0X00000001;
    UINT iMask_2 = 0X00000001;

    iMask_1 = iMask_1 << (iPos_1-1);
    iMask_2 = iMask_2 << (iPos_2-1);

    UINT iMask = iMask_1 | iMask_2;

    return ~iMask;
}

int main()
{
    UINT iNo = 0;
    UINT iPos1_1 = 0;
    UINT iPos1_2 = 0;
    UINT iRet = 0;

    printf("ENTER THE NUMBER : ");
    scanf("%d",&iNo);

    printf("ENTER BIT POSITION: ");
    scanf("%d",&iPos1_1);

    printf("ENTER BIT POSITION: ");
    scanf("%d",&iPos1_2); 

    iRet = DYNAMIC_MASK(iPos1_1,iPos1_2);
    iRet = OFF_BIT(iRet,iNo);

    printf("UPDATED NUMBER : %d\n",iRet);

    return 0;
}