#include<stdio.h>

void Display_Binary(int iNo)
{
    unsigned int Binary[8];
    int iCnt = 0;

    while(iNo!= 0)
    {
        Binary[iCnt] =  iNo%2;
        iNo = iNo/2;
        iCnt++;
    }

    int i = 0;
    // printf("%d",iCnt);

    for(i = iCnt ;i>=0;i--)
    {
        printf("%d",Binary[i]);
    }
    printf("\n");
}

int main()
{
    int iNo = 0;
    printf("ENTER THE NUMBER :\n");
    scanf("%d",&iNo);

    Display_Binary(iNo);

    return 0;
}