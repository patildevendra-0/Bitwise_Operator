#include<stdio.h>

typedef unsigned int UINT;

int Count_OnBits(UINT iNo)
{
    UINT iDigit = 0;
    int iCOunt = 0;

    while(iNo!=0)
    {
        iDigit = iNo % 2;
        if(iDigit == 1)
        {
            iCOunt++;
        }
        iNo = iNo / 2;
    }

    return iCOunt;
}

int main()
{
    UINT iNo = 0;
    int iRet = 0;

    printf("ENTER THE NUMBER : \n");
    scanf("%d",&iNo);

    iRet = Count_OnBits(iNo);
    printf("COUNT OF ON BITS :%d\n",iRet);

    return 0;
}