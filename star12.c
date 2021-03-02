//program to print star pattern
#include <stdio.h>
void main()
{
    int rows,i,j,num,r,a;
    system("cls");
    printf("How many rows you want to print in star pattern ");
    scanf("%d",&rows);

    for(i=1;i<=rows;i++)
    {
        for(j=1;j <= rows*2-1;j++)
        {
            if(j>=i && j<=(rows*2)-i)
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
