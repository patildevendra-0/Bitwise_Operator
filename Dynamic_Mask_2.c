#include<stdio.h>
#include<stdbool.h>

typedef unsigned int UINT;

bool CHECK_BIT(UINT iNo,UINT iMask)
{
    UINT iAns = iMask & iNo;
    return iAns;
} 

int DYNAMIC_MASK(int iPos)
{
    UINT iMask = 0X00000001;
    iMask = iMask <<(iPos-1);
    return iMask;
}

int main()
{
    UINT iNo = 0;
    UINT iPos = 0;
    UINT iRet = 0;
    bool bRet = false;

    printf("ENTER THE NUMBER :");
    scanf("%d",&iNo);

    printf("ENTER THE BIT POSITION : ");
    scanf("%d",&iPos);

    iRet = DYNAMIC_MASK(iPos);
    bRet = CHECK_BIT(iNo,iRet);

    if(bRet == true)
    {
        printf("%d BIT IS ON..\n",iPos);
    }
    else
    {
        printf("%d BIT IS OFF..\n",iPos);
    }

    return 0;
}