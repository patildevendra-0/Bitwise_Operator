#include<stdio.h>

typedef unsigned int UINT;

int OFF_BIT(UINT iNo)
{
    
}

int main()
{
    UINT iNo = 0;
    UINT iRet = 0;

    printf("ENTER THE NUMBER: \n");
    scanf("%d",&iNo);

    iRet = OFF_BIT(iNo);
    printf("UATED NUMBER: %d\n",iNo);

    return 0;
}