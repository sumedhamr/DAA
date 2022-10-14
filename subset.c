#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bool[100];
void subsetsum(int arr[],int i,int n,int req);
void main(){
    
    int n;
    int sum;
    for(int i = 0;i<100;i++) bool[i] = 0;
    
    printf("Enter the no of elements and the elements respectively of the array\n");
    scanf("%d",&n);
    int arr[n];
    for(int i = 0;i<n;i++) scanf("%d",&arr[i]);
    printf("Enter the required sum\n");
    scanf("%d",&sum);
    printf("All combinations are:\n");
    subsetsum(arr,n-1,n,sum);
    
}

void subsetsum(int arr[],int i,int n,int req){
    if(i<0 && req!=0) return;
    if(i<0 && req==0) {
        for(int j = 0;j<n;j++)
            if(bool[j]==1)
                printf("%d",arr[j]);
        printf("\n");
        return;
    } 
    
    if(arr[i]<=req && bool[i]!=1){
        bool[i] = 1;
        subsetsum(arr,i-1,n,req-arr[i]);
    }
    bool[i] = 0;
    subsetsum(arr,i-1,n,req);
}





