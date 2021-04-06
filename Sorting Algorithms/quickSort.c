#include <stdio.h>
#include <stdlib.h>

void quick(int arr[], int n, int start, int end, int *loc)
{
    int left, right, temp;
    left = start;
    right = end;
    *loc = start;
step2:
    while (arr[*loc] <= arr[right] && *loc != right)
        right--;
    if (*loc == right)
        return;
    if (arr[*loc] > arr[right])
    {
        temp = arr[*loc];
        arr[*loc] = arr[right];
        arr[right] = temp;
        *loc = right;
    }
    goto step3;
step3:
    while (arr[left] <= arr[*loc] && left != *loc)
        left++;

    if (*loc == left)
        return;
    if (arr[left] > arr[*loc])
    {
        temp = arr[left];
        arr[left] = arr[*loc];
        arr[*loc] = temp;
        *loc = left;
    }
    goto step2;
}

void quickSort(int Array[],int Num)
{
    int top = -1,low[10],up[10],beg,end,loc;

    if(Num >1)
    {
        top++;
        low[top] =0;
        up[top] = Num -1;

    }
    while(top != -1)
    {
        beg = low[top];
        end = up[top];
        top--;
        quick(Array,Num,beg,end,&loc);
        if(beg < loc-1)
        {
            top=top+1;
            low[top] = beg;
            up[top] = loc -1;
        }
        if(loc+1 < end)
        {
            top++;
            low[top] = loc+1;
            up[top] = end;
        }
    }
}

void main()
{
    int A[] = {44,33,11,55,88,90,40,60,99,22,88,66};
    int N = 12;
    system("cls");
    quickSort(A,N);
    for(int i=0;i<12;i++)
    {
        printf(" %d",A[i]);
    }
    system("pause");
}