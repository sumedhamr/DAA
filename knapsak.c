#include <stdio.h>
#include <stdlib.h>

int max(int a,int b);
void knapsack(int n,int m,int p[10],int w[10],int v[20][20]);
void optimumchoices(int n,int m,int p[10],int w[10],int v[20][20]);

int main()
{
    int p[10],v[20][20],w[10],m,n,i;
    printf("enter the no of objects\n");
    scanf("%d",&n);
    printf("enter the weights of objects\n");
    for(i=1;i<=n;i++)
    scanf("%d",&w[i]);
    printf("enter the profit of objects\n");
    for(i=1;i<=n;i++)
    scanf("%d",&p[i]);
    printf("enter the cepasity \n");
    scanf("%d",&m);
    knapsack(n,m,p,w,v);
    optimumchoices(n,m,p,w,v);
}

void knapsack(int n,int m,int p[10],int w[10],int v[20][20])
{
    int i,j;
    for(i=0;i<=n;i++)
     {
     for(j=0;j<=m;j++)
      {
         if(i==0 || j==0)
          v[i][j]=0;
         else if(j<w[i])
         {
            v[i][j]=v[i-1][j];
         }
         else
         {
             v[i][j]=max(v[i-1][j], v[i-1][j-w[i]]+p[i]);
         }
         printf("%d ",v[i][j]);
      }
      printf("\n");
     }
}

void optimumchoices(int n,int m,int p[10],int w[10],int v[20][20])
{
    printf("optimum solution is %d\n",v[n][m]);
    int i,j;
    i=n;
    j=m;
    printf("objects selected are\n");
    while(i!=0 && j!=0)
    {
        if(v[i][j]!=v[i-1][j])
         {
             printf("%d ",i);
             j=j-w[i];
         }
        i=i-1;
    }
}

int max(int a,int b)
{
    return (a>b?a:b);
}









