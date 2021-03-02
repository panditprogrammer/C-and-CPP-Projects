//program to print star pattern
#include <stdio.h>
void main()
{
    int rows,i,j,num,r,a=0;
    system("cls");
    printf("How many rows you want to print in star pattern ");
    scanf("%d",&rows);

    for(i=1;i<=rows;i++)
    {
        i<=(rows+1)/2?a++:a--;
        for(j=1;j<=rows;j++)
        {
            if(j<=a)
            {
                printf("*");
            }
            else
                printf(" ");
        }
        printf("\n");
    }
    system("pause");
}
