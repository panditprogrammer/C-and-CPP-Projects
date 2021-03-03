//Bubble Sort Algorithms
#include <stdio.h>
void sort(int a[],int);
void main()
{
    int i,arr[5];
    system("cls");
    printf("Enter  5 numbers ");
    for(i=0;i<=4;i++)
        scanf("%d",&arr[i]);
    sort(arr,4);
    for(i=0;i<=4;i++)
        printf("%d ",arr[i]);
    system("pause");
}
void sort(int a[],int n)
{
    int round ,i,temp;
    for(round =0;round<=n-1;round++)
        for(i=0;i<=n-1-round;i++)
            if(a[i]>a[i+1])
    {
        temp = a[i];
        a[i] = a[i+1];
        a[i+1] = temp;
    }
}
