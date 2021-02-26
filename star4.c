//star pattern in C
#include <stdio.h>
void main()
{
    int i,j,n;
    system("cls");
    printf("Enter how many rows you want to print in star pattern ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){

        for(j=1;j<=n;j++){

                if(j>=i)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }

        }
        printf("\n");
    }
    system("pause");
}
