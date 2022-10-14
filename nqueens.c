#include <stdio.h>
#include<stdlib.h>
int cnt=0;
void nqueens(int row,int n,int a[100][100]);
int place(int a[100][100],int row,int col,int n);

int main()
{
    int a[100][100],i,j,n;
    printf("enter the no od rows\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
    for(j=0;j<n;j++){
    a[i][j]=0;}}
    nqueens(0,n,a);
    printf("%d",cnt);
}

void nqueens(int row,int n,int a[100][100])
{
    int i,j;
    if(row==n)
    {
        for(i=0;i<n;i++){
        for(j=0;j<n;j++){
        if(a[i][j]==1){
        printf("(%d,%d)  ",i,j);}}}
        printf("\n");
        cnt++;
        return;
    }
    for(i=0;i<n;i++)
    {
        if(place(a,row,i,n)==1)
        {
            a[row][i]=1;
            nqueens(row+1,n,a);
            a[row][i]=0;
        }
    }
}

int place(int a[100][100],int row,int col,int n)
{
    int i,j;
    for(i=0;i<=row-1;i++)
    {
        if(a[i][col]==1)
        return 0;
    }
    for(i=row,j=col;i>=0 && j>=0;i--,j--)
    {
        if(a[i][j]==1)
        return 0;
    }
    for(i=row,j=col;i>=0 && j<n;i--,j++)
    {
        if(a[i][j]==1)
        return 0;
    }
    return 1;
}
