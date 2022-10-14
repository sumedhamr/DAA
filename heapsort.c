#include<stdio.h>
#include<stdlib.h>

#define MAX 100
void heapify(int a[MAX],int n);
void heapsort(int a[MAX],int n);

int main()
{
    int i,j,n,a[MAX];
    printf("enter the no of elements\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    	scanf("%d",&a[i]);
    heapify(a,n);
    //for(i=1;i<=n;i++)
    //	printf("%d ",a[i]);
    heapsort(a,n);
    printf("the sorted array is\n");
    for(i=1;i<=n;i++)
    	printf("%d ",a[i]);
    return 0;
}

void heapify(int a[MAX],int n)
{
    int i,j,k,v,flag;
    for(i=n/2;i>=1;i--)
    {
        k=i;
        v=a[k];
        flag=0;
        while(!flag && 2*k<=n)
        {
            j=2*k;
            if(j<n)
            {
                if(a[j]<a[j+1])
                {
                    j=j+1;
                }
            }
            if(v>=a[j])
            	flag=1;
            else
            {
                a[k]=a[j];
                k=j;
            }
        }
        a[k]=v;
    }
}

void heapsort(int a[MAX],int n)
{
    int temp,i;
    for(i=n;i>1;i--)
    {
        temp=a[1];
        //printf("%d ",temp);
        
        a[1]=a[i];
        a[i]=temp;
        heapify(a,i-1);
    }
}








