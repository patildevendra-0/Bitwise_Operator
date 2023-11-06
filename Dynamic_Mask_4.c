#include<stdio.h>

typedef unsigned int UINT;

int TOGGLE_BIT(UINT iMask,UINT iNo)
{
    return iMask ^ iNo;
}

int DYNAMIC_MASK(UINT iPos_1,UINT iPos_2)
{
    UINT iMask1 = 0X00000001;
    UINT iMask2 = 0X00000001;

    UINT Mask = 0;

    iMask1 = iMask1 << (iPos_1-1);
    iMask2 = iMask2 << (iPos_2-1);

    Mask = iMask1 | iMask2;
    return Mask;
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
    iRet = TOGGLE_BIT(iRet,iNo);

    printf("UPDATED NUMBER : %d\n",iRet);

    
    return 0;
}