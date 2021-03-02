//program to print number pattern
#include <stdio.h>
void main()
{
    int rows,i,j,num;
    system("cls");
    printf("How many rows you want to print in number pattern ");
    scanf("%d",&rows);

    for(i=1;i<=rows;i++)
    {
        num = 1;
        for(j=1;j<=rows*2-1;j++)
        {
            if(j>=rows+1-i && j<= rows-1+i)
            {
                printf("%d",num);

                j<rows?num++:num--;

            }
            else
                printf(" ");
        }
        printf("\n");
    }
    system("pause");
}
