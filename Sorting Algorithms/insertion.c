//insertion sort
#include <stdio.h>
#include <stdlib.h>

void insertionSort(int A[],int N)
    {
        int i,j,temp;

        for(i=0;i<N;i++)
        {
            temp = A[i];
            for(j=i-1;j>=0 && temp<A[j];j--)
                A[j+1] = A[j];
            A[j+1] = temp;
        }
    }

void main()
{
    int i;
    system("cls");
    printf("Insertion Sort\n ");
    int A[] = {34,67,23,43,80,12};
    int n = 6;
    insertionSort(A,n);
    for(i=0;i<6;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
    system("pause");
}