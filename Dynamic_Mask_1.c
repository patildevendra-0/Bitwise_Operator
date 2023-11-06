#include<stdio.h>
#include<stdbool.h>
typedef unsigned int UINT;

/*
    0000 0000 0000 0000 0000 0100 0100 0110
    0000 0000 0000 0000 0000 0000 0100 0000
*/

bool Check_Bit(UINT iNo,UINT iMask)
{
    UINT iAns = 0;
    iAns = iNo & iMask;
    
    if(iAns == iMask)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int DYNAMIC_MASK(UINT iPos)
{
    UINT iMask = 0X00000001;
    iMask = iMask << (iPos-1);
    return iMask;
}

int main()
{
    UINT iNo = 0;
    UINT iPos = 0;
    UINT iRet = 0;
    bool bRet = false;

    printf("ENTER THE NUMBER : ");
    scanf("%d",&iNo);

    printf("ENTER THE POSITION : ");
    scanf("%d",&iPos);

    iRet = DYNAMIC_MASK(iPos);
    bRet = Check_Bit(iNo,iRet);

    if(bRet == true)
    {
        printf("%d BIT IS ON \n",iPos);
    }
    else
    {
        printf("%d BIT IS OFF \n",iPos);
    }

    return 0;
}