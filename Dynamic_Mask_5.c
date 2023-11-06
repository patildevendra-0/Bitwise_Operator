#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef unsigned int UINT;

bool CHECK_BIT(UINT iMask, UINT iNo)
{
    UINT iAns = iMask & iNo;
    if (iAns == iMask)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int OFF_BIT(UINT iMask, int iNo)
{
    UINT iAns = ~iMask & iNo;
    return iAns;
}

int Demo(UINT iNo)
{
    static UINT iMask = 0X00000000;
    iMask = iNo | iMask;
    return iMask;
}

int DYNAMIC_MASK(UINT *ptr, int iSize)
{
    UINT *Mask_Array = (UINT *)malloc(sizeof(UINT) * iSize);
    UINT iMask = 0X00000001;
    UINT iMask_final = 0XFFFFFFFF;

    for (int iCnt = 0; iCnt < iSize; iCnt++)
    {
        iMask = iMask << ((ptr[iCnt]) - 1);
        Mask_Array[iCnt] = iMask;
        iMask = 0X00000001;
    }

    for (int iCnt = 0; iCnt < iSize; iCnt++)
    {
        iMask_final = Demo(Mask_Array[iCnt]);
    }
    free(Mask_Array);
    return iMask_final;
}


int main()
{
    UINT iNo = 0;
    UINT *Arr = NULL;
    int iSize = 0;
    UINT iRet = 0;
    bool bRet = false;
    int iValue = 0;

    while (1)
    {
        printf("1 : CHECK BIT ON OR OFF \n");
        printf("2 : OFF PARTICULAR BIT OF NUMBER \n");
        printf("3 : TOGGLE BIT OF PARTICULAR BIT \n");
        printf("-------------------------------------\n");
        printf("ENTER THE VALUE FOR TASK: ");
        scanf("%d", &iValue);

        switch (iValue)
        {
        case 1:
            printf("ENTER THE NUMBER: ");
            scanf("%d", &iNo);

            printf("ENTER THE NUMBER OF BITS THAT YOU WANT CHECK : ");
            scanf("%d", &iSize);

            Arr = (UINT *)malloc(iSize * sizeof(UINT));
            int iCnt = 0;

            for (iCnt = 0; iCnt < iSize; iCnt++)
            {
                scanf("%d", &Arr[iCnt]);
            }

            iRet = DYNAMIC_MASK(Arr, iSize);
            bRet = CHECK_BIT(iRet, iNo);

            if (bRet == true)
            {
                for (iCnt = 0; iCnt < iSize; iCnt++)
                {
                    printf("%d\t", Arr[iCnt]);
                }
                printf("BIT ON...\n");
            }
            else
            {
                printf("BIT OFF..\n");
            }
            free(Arr);
            break;
        case 2:
             printf("ENTER THE NUMBER: ");
            scanf("%d", &iNo);

            printf("ENTER THE NUMBER OF BITS THAT YOU WANT TO OFF : ");
            scanf("%d", &iSize);

            Arr = (UINT *)malloc(iSize * sizeof(UINT));

            for (iCnt = 0; iCnt < iSize; iCnt++)
            {
                scanf("%d", &Arr[iCnt]);
            }

            iRet = DYNAMIC_MASK(Arr, iSize);
            iRet = OFF_BIT(iRet, iNo);

            printf("UPDATED NUMBER :%d\n",iRet);

            free(Arr);
            break;
        case 3:
            return -1;    
        default:
            break;
        }
    }

    free(Arr);
    return 0;
}