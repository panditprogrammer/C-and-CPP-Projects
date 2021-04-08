//counting sort algorithms
#include <stdio.h>
#include<stdlib.h>

void countingSort(int arr[],int n,int barr[],int k)
{
	int i,j,c[k];
	
	for(i=0;i<k;i++)
	{
		c[i]=0;
	}
	
	for(j=0;j<n;j++)
	{
		c[arr[j]] = c[arr[j]]+1;
	}
	
	for(i=1;i<k;i++)
	{
		c[i] = c[i]+c[i-1];
	}
	
	for(j=n-1;j>=0;j--)
	{
		barr[c[arr[j]]-1] = arr[j];
		c[arr[j]] = c[arr[j]]-1;
	}
}


void main()
{
int A[] = {5,9,4,5,3,6,8,5,4,8,7,4,6,9,7},B[15],k=10,n=15;

	system("cls");
	//calling the function
	countingSort(A,n,B,k);
	
	for(int i=0;i<n;i++)
	{
		printf("%d ",B[i]);
	}
	
	system("pause");

}
