//star pattern in C
#include <stdio.h>
void main()
{
    int i,j,n,flag;
    system("cls");
    printf("Enter how many rows you want to print in star pattern ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        flag = 1;
        for(j=1;j<=n*2-1;j++){

                if(j>= n+1-i && j <=  n-1+i&& flag)
                {
                    printf("*");
                    flag = 0;
                }
                else
                {
                    printf(" ");
                    flag = 1;
                }

        }
        printf("\n");

    }
    system("pause");
}
