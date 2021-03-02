//program to print alphabet pattern
#include <stdio.h>
void main()
{
    int rows,i,j;
    char ch;
    system("cls");
    printf("How many rows you want to print in alphabet pattern ");
    scanf("%d",&rows);

    for(i=1;i<=rows;i++)
    {
        ch ='A';
        for(j=1;j<=rows*2-1;j++)
        {
            if(j>=rows+1-i && j<= rows-1+i)
            {
                printf("%c",ch);

                j<rows?ch++:ch--;

            }
            else
                printf(" ");
        }
        printf("\n");
    }
    system("pause");
}
