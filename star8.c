//program to print star pattern
#include <stdio.h>
void main()
{
    int n,i,j;
    system("cls");
    printf("Enter number of rows you want to print in star pattern ");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=(2*n-1);j++){

            if(j<=n+1-i || j>= n-1+i)
                    printf("*");
            else
                    printf(" ");
        }

    printf("\n");
    }

    system("pause");


}
