//program to print digit pattern
#include <stdio.h>
void main()
{
    int rows,i,j,num,r,a;
    system("cls");
    printf("How many rows you want to print in digit pattern ");
    scanf("%d",&rows);

    for(i=1;i<=rows;i++)
    {
        a=rows-i;
        for(j=1;j <= rows*2-1;j++)
        {
            if(j<=rows+1-i)
            {
                printf("%d ",a);
                a--;
            }
            else
                printf(" ");
        }
        printf("\n");
    }
    system("pause");
}
