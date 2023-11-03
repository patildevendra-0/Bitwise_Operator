#include<stdio.h>
typedef unsigned int UINT;

int Count_ON_Bits(UINT iNo)
{
    UINT iDigit = 0;
    int iCount = 0;

    while(iNo != 0)
    {
        iDigit = iNo % 2;
        iCount = iDigit+iCount;
        iNo = iNo/2;
    }

    return iCount;
}

int main()
{   
    UINT iNo = 0;
    int iRet = 0;

    printf("ENTER THE NUMBER: \n");
    scanf("%d",&iNo);

    iRet = Count_ON_Bits(iNo);
    printf("COUNT OF ON BITS : %d\n",iRet);

    return 0;
}