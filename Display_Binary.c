#include<stdio.h>

typedef unsigned int UINT;

void Display_Binary(UINT iNo)
{
    UINT iDigit = 0;
    
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
    UINT iNo = 0;
    printf("ENTER THE NUMBER :\n");;
    scanf("%d",&iNo);
    
    Display_Binary(iNo);

    return 0;
}