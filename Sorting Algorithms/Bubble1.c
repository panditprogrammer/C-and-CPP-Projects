// program for bubble sort algorithm
#include <stdio.h>
void bubbleSort(int a[],int n);
void main()
{
    int arr[] = {40,30,70,20,80,77,33,20,8};
    int i,n,round;
    system("cls");
    n = 8;//number of element
    bubbleSort(arr,n);
    //printing after sorting array
    for(i=0;i<=8;i++)
        printf("%d ",arr[i]);
    printf("\n");
    system("pause");
}

void bubbleSort(int ar[],int N)
{
    int round,i,temp,detect;

    for(round=1;round<=N-1;round++)
    {
        detect = 0;
        for(i=0;i<=N-round;i++)
            if(ar[i]>ar[i+1])
        {
            detect = 1;
            temp = ar[i];
            ar[i] = ar[i+1];
            ar[i+1] = temp;
        }
        if(detect==0)
            return; //checking round
    }
}
