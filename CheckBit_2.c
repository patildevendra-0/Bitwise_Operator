#include<stdio.h>
#include<stdbool.h>
typedef unsigned int UINT;

/*  
    0000 0000 0000 0000 0000 0000 0001 0010
     0    0    0    0    0    0     1    2
    0X00000012
*/

bool Check_BIT(UINT iNo)
{
    UINT iMask = 0X00000012;
    UINT iResult = 0;

    iResult = iMask & iNo;
    if(iResult == iMask)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{   
    UINT iNo = 0;
    bool bRet = false;

    printf("ENTER THE NUMBER: \n");
    scanf("%d",&iNo);

    bRet = Check_BIT(iNo);
    if(bRet == true)
    {
        printf("2 AND 5 BIT IS ON \n");
    }
    else
    {
        printf("2 AND 5 BIT IS OFF \n");
    }


    return 0;
}