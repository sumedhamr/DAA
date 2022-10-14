#include<stdio.h>
#include<stdlib.h>

#define SIZE 100

void mergesort(int A[SIZE],int l,int r);
void merge(int A[SIZE],int l,int m,int r);

int main()
{
 int n,i,A[SIZE];
 printf("enter the no of elements\n");
 scanf("%d",&n);
 printf("enter the array elements\n");
 for(i=0;i<n;i++)
 scanf("%d",&A[i]);
 mergesort(A,0,n-1);
 printf("sorted array is\n");
 for(i=0;i<n;i++)
 printf("%d ",A[i]);
 return 0;
}
void mergesort(int A[SIZE],int l,int r)
{
 int m;
 if(l<r)
 {
  m=(l+r)/2;
  mergesort(A,l,m);
  mergesort(A,m+1,r);
  merge(A,l,m,r);
 }
}
void merge(int A[SIZE],int l,int m,int r)
{
 int i,j,k,B[SIZE];
 i=l;
 j=m+1;
 k=l;
 while(i<=m&&j<=r)
 {
  if(A[i]>=A[j])
   B[k++]=A[j++];
  if(A[i]<A[j])
   B[k++]=A[i++];
 }
 while(i<=m)
  B[k++]=A[i++];
 while(j<=r)
  B[k++]=A[j++];
 for(i=l;i<=r;i++)
 A[i]=B[i];
}
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
