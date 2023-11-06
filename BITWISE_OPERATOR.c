#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef unsigned int UINT;

/*
    1111 1111 1111 1111 1111 1111 0000 0000      <<
    0000 0000 1111 1111 1111 1111 1111 1111      >>
    0000 0000 1111 1111 1111 1111 0000 0000       &

    0000 0000 0100 0010 0010 0010 0000 0000       ^
    0000 0000 1011 1101 1101 1101 0000 0000
*/

int Toggle_Range(UINT Start,UINT End,UINT iNo)
{
    UINT Start_Bit = 0XFFFFFFFF;
    UINT End_bit =   0XFFFFFFFF;
    UINT Final_Mask = 0;

    Start_Bit = Start_Bit <<(Start-1);
    End_bit   = End_bit >>(32-End);

    Final_Mask = Start_Bit & End_bit;

    Final_Mask = Final_Mask ^ iNo;

    return Final_Mask; 

}

int Count_On_Bits(UINT iNo)
{
    UINT iDigit = 0;
    int iCount = 0;

    while (iNo != 0)
    {
        iDigit = iNo % 2;
        if (iDigit == 1)
        {
            iCount++;
        }
        iNo = iNo / 2;
    }
    return iCount;
}

int OFF_BIT(UINT iNo, UINT iMask)
{
    UINT iAns = ~iMask & iNo;
    return iAns;
}

int ON_BIT(UINT iNo, UINT iMask)
{
    UINT iAns = iMask | iNo;
    return iAns;
}

bool Check_Bit_On_Off(UINT iNo, UINT iMask)
{
    UINT iAns = iMask & iNo;
    if (iMask == iAns)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Toggle_Bits(UINT iNo, UINT iMask)
{
    UINT iAns = iNo ^ iMask;
    return iAns;
}

int Display_Binary(UINT iNo)
{
    UINT iDigit = 0;
    if (iNo < 0)
    {
        iNo = -iNo;
    }
    printf("Binary of %d : ", iNo);
    while (iNo != 0)
    {
        iDigit = iNo % 2;
        printf("%d", iDigit);
        iNo = iNo / 2;
    }
    printf("\n");
}

int resetStaticVariable()
{
    static UINT myStaticVar = 0; // Initialize the static variable
    myStaticVar = 0;             // Reset the static variable to 0
    return myStaticVar;
}

int Mask_Creation(UINT iMask, int iCnt)
{
    static UINT iAns = 0X00000000;
    UINT iRet = 0;

    if (iCnt == 0)
    {
        iRet = resetStaticVariable();
        iAns = iMask | iRet;
        return iAns;
    }
    else
    {
        iAns = iMask | iAns;
        return iAns;
    }
}

int DYNAMIC_MASK(UINT *ptr, int iSize)
{
    UINT iMask = 0X00000001;
    UINT *iMask_Array = NULL;
    UINT Final_Mask = 0XFFFFFFFF;
    int iCnt = 0;

    iMask_Array = (UINT *)malloc(sizeof(UINT) * iSize);

    for (iCnt = 0; iCnt < iSize; iCnt++)
    {
        iMask = iMask << ((ptr[iCnt]) - 1);
        iMask_Array[iCnt] = iMask;
        iMask = 0X00000001;
    }

    for (iCnt = 0; iCnt < iSize; iCnt++)
    {
        if (iMask_Array[0])
        {
            Final_Mask = Mask_Creation(iMask_Array[iCnt], iCnt);
        }
        else
        {
            Final_Mask = Mask_Creation(iMask_Array[iCnt], iCnt);
        }
    }
    // printf("DYNAMIC MASK VALUE : %d\n",Final_Mask);
    free(iMask_Array);
    return Final_Mask;
}

int main()
{
    UINT iNo = 0;
    UINT iSize = 0;
    UINT *Arr = NULL;
    int iCnt = 0;
    UINT iRet = 0;
    int Switch_Value = 0;
    bool bRet = false;

    while (1)
    {
        printf("_______________________________________________________\n");
        printf("OPERATION 1 : Display Binary of Given Number.\n");
        printf("OPERATION 2 : Check Particular Bit On or Off.\n");
        printf("OPERATION 3 : On Particular Bit of Given Number.\n");
        printf("OPERATION 4 : Off Particular Bit of Given Number.\n");
        printf("OPERATION 5 : Toggle Bits of Given Number.\n");
        printf("OPERATION 6 : Toggle Range of Bits of Given Number.\n");
        printf("OPERATION 7 : Count on Bits of Given Number.\n");
        printf("OPERATION 8 : Exit from Appliaction.\n");
        printf("_______________________________________________________\n");
        printf("ENTER THE OPERATION NUMBER THAT YOU WANT PERFORM : ");
        scanf("%d", &Switch_Value);
        printf("%d\n", Switch_Value);
        if (Switch_Value == 0)
        {
            printf("--------------------------------------------------------\n");
            printf("Application Terminated...!!!!!\n");
            printf("PLEASE ENTER INTEGERS ONLY-------(NOT CHARACHTER/STRING)\n");
            printf("---------------------------------------------------------\n");
            break;
        }
        else
        {
            switch (Switch_Value)
            {
            case 1:
                printf("_______________________________________________________\n");
                printf("ENTER THE NUMBER :");
                scanf("%d", &iNo);
                Display_Binary(iNo);
                printf("_______________________________________________________\n");
                break;

            case 2:
                printf("_______________________________________________________\n");
                printf("ENTER THE VALUE : ");
                scanf("%d", &iNo);

                printf("ENTER THE NUMBER OF BITS THAT YOU WANT TO CHECK : ");
                scanf("%d", &iSize);
                Arr = (UINT *)malloc(sizeof(UINT) * iSize);

                for (iCnt = 0; iCnt < iSize; iCnt++)
                {
                    scanf("%d", &Arr[iCnt]);
                }

                iRet = DYNAMIC_MASK(Arr, iSize);
                bRet = Check_Bit_On_Off(iNo, iRet);
                if (bRet == true)
                {
                    printf("BIT ON \n");
                }
                else
                {
                    printf("BIT OFF \n");
                }
                free(Arr);
                printf("_______________________________________________________\n");
                break;

            case 3:

                printf("_______________________________________________________\n");
                printf("ENTER THE VALUE : ");
                scanf("%d", &iNo);

                printf("ENTER THE NUMBER OF BITS THAT YOU WANT TO ON : ");
                scanf("%d", &iSize);
                Arr = (UINT *)malloc(sizeof(UINT) * iSize);

                for (iCnt = 0; iCnt < iSize; iCnt++)
                {
                    scanf("%d", &Arr[iCnt]);
                }

                iRet = DYNAMIC_MASK(Arr, iSize);
                iRet = ON_BIT(iNo, iRet);
                printf("UPDATED NUMBER AFTER ON BIT : %d\n", iRet);
                free(Arr);
                iNo = 0;
                iSize = 0;
                iCnt = 0;
                printf("_______________________________________________________\n");
                break;

            case 4:
                printf("_______________________________________________________\n");
                printf("ENTER THE VALUE : ");
                scanf("%d", &iNo);

                printf("ENTER THE NUMBER OF BITS THAT YOU WANT TO ON : ");
                scanf("%d", &iSize);
                Arr = (UINT *)malloc(sizeof(UINT) * iSize);

                for (iCnt = 0; iCnt < iSize; iCnt++)
                {
                    scanf("%d", &Arr[iCnt]);
                }

                iRet = DYNAMIC_MASK(Arr, iSize);
                iRet = OFF_BIT(iNo, iRet);
                printf("UPDATED NUMBER AFTER OFF BIT : %d\n", iRet);
                free(Arr);
                iNo = 0;
                iSize = 0;
                iCnt = 0;
                printf("_______________________________________________________\n");
                break;

            case 5:
                printf("_______________________________________________________\n");
                printf("ENTER THE VALUE : ");
                scanf("%d", &iNo);

                printf("ENTER THE NUMBER OF BITS THAT YOU WANT TO Toggle : ");
                scanf("%d", &iSize);
                Arr = (UINT *)malloc(sizeof(UINT) * iSize);

                for (iCnt = 0; iCnt < iSize; iCnt++)
                {
                    scanf("%d", &Arr[iCnt]);
                }

                iRet = DYNAMIC_MASK(Arr, iSize);
                iRet = Toggle_Bits(iNo, iRet);
                printf("UPDATED NUMBER AFTER Toggle BIT : %d\n", iRet);
                free(Arr);
                iNo = 0;
                iSize = 0;
                iCnt = 0;
                printf("_______________________________________________________\n");
                break;

            case 6:
                printf("_______________________________________________________\n");

                UINT Start_Bit = 0;
                UINT End_Bit = 0;
                printf("ENTER THE NUMBER : ");
                scanf("%d",&iNo);

                printf("ENTER THE STARTING BIT : ");
                scanf("%d",&Start_Bit);

                printf("ENTER THE ENDING BIT : ");
                scanf("%d",&End_Bit);

                iRet = Toggle_Range(Start_Bit,End_Bit,iNo);
                printf("UPDATED NUMBER : %d\n",iRet);


                printf("_______________________________________________________\n");
                break;

            case 7:
                printf("_______________________________________________________\n");
                printf("ENTER THE VALUE : ");
                scanf("%d", &iNo);

                iRet = Count_On_Bits(iNo);
                printf("COUNT OF ON BITS : %d\n", iRet);
                printf("_______________________________________________________\n");
                break;

            case 8:
                printf("Thank You !");
                return -1;
                break;

            default:
                printf("INVALID ARGUMENT ....!\n");
                break;
            }
        }
    }

    return 0;
}