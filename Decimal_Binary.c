#include<stdio.h>

int Convert_Binary(int iNo)
{
    int iDigit = 0;
    int itemp = 0;

    printf("BINARY NUMBER OF %d: \t",iNo);
    while(iNo!=0)
    {
        iDigit = iNo%2;
        printf("%d",iDigit);
        iNo = iNo/2;
    }
    printf("\n");
}

int main()
{
    int iNo = 0;
    int iRet = 0;

    printf("ENTER THE NUMBER: ");
    scanf("%d",&iNo);

    iRet = Convert_Binary(iNo);

    return 0;
}