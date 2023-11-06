#include<stdio.h>
typedef unsigned int UINT;

/*      
        0000 0000 0000 0000 0100 0100 0100 0100
        0000 0000 0000 0000 0100 0101 0010 0000
          0   0    0    0     4    5   2    0

          0X00004520
*/

int TOGGLE_BIT(UINT iNo)
{
    UINT iMask = 0X00004520;
    UINT iAns = 0;

    iAns = iMask ^ iNo;
    return iAns;
}

int main()
{
    UINT iNo = 0;
    UINT iRet = 0;

    printf("ENTER THE NUMBER :\n");
    scanf("%d",&iNo);

    iRet = TOGGLE_BIT(iNo);
    printf("UPDATED NUMBER: %d\n",iRet);

    return 0;
}