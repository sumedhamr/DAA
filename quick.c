#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

void quicksort(int A[SIZE],int l,int r);
int partition(int A[SIZE],int l,int r);
//void swap(int A[i],int A[j]);

int main()
{
 int n,i,A[SIZE];
 printf("enter the no of elements\n");
 scanf("%d",&n);
 printf("enter the array elements\n");
 for(i=0;i<n;i++)
 scanf("%d",&A[i]);
 quicksort(A,0,n-1);
 printf("sorted array is\n");
 for(i=0;i<n;i++)
 printf("%d ",A[i]);
 return 0;
}

void quicksort(int A[SIZE],int l,int r)
{
 int s;
 if(l<r)
 {
  s=partition(A,l,r);
  quicksort(A,l,s-1);
  quicksort(A,s+1,r);
 }
}

int partition(int A[SIZE],int l,int r)
{
 int pivot,i,j;
 pivot=A[l];
 i=l+1;
 j=r;
 while(1)
 {
  while(pivot>=A[i]&&i<=r)
  i++;
  while(pivot<A[j]&&j>=l)
  j--;
  if(i<j)
  {
  //swap(A[i],A[j]);
   int temp;
   temp=A[i];
   A[i]=A[j];
   A[j]=temp;
  }
  else
  {
   //swap(A[l],A[j]);
   int temp1;
   temp1=A[l];
   A[l]=A[j];
   A[j]=temp1;
   return j;
  }
 }
}

//void swap(int A[i],int A[j])
//{
// int temp;
// int i,j;
 //temp=A[i];
 //A[i]=A[j];
// A[j]=temp;
//}

 


















