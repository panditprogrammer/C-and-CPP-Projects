//program for selection sort algorithms
#include <stdio.h>
#include <stdlib.h>
void main()
{
    int A[]={34,56,2,83,23};
    int k ,temp,index;
    system("cls");
    for(k=0;k<=5;k++)
    {
        index = min(A,k,5);
        temp = A[k];
        A[k] = A[index];
        A[index] = temp;
    }
    for(k=0;k<=4;k++)
        printf(" %d",A[k]);

    system("pause");
}

//min index
int min(int a[],int k,int n)
{
    int index ,j,mininum;
    mininum = a[k];
    index = k;
    
    for(j=k+1;j<=n-1;j++)
    {
        if(mininum>a[j])
        {
            mininum = a[j];
            index = j;
        }
    }
    return index;
}

