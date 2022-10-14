#include <stdio.h>
#include<stdlib.h>


int out[10];
int wow=0;
int in[10]={0};

void dfs(int a[10][10],int n,int v[10],int src);
void vertexrml(int n,int a[10][10],int in[10],int v[10]);

int main()
{
   int a[10][10],v[10],n,i,j,source;
   int cnt=0;
   printf("enter the no of nodes\n");
   scanf("%d",&n);
   printf("read the adj matrix\n");
   for(i=0;i<n;i++)
   for(j=0;j<n;j++)
   {
       scanf("%d",&a[i][j]);
       if(a[i][j]==1)
       in[j]++;
   }
   
   printf("calling dfs\n");
   for(i=0;i<n;i++)
   v[i]=0;
   for(i=0;i<n;i++)
   {
       if(v[i]==0)
       {
          printf("%d  ",i);
          dfs(a,n,v,i);
          cnt++;
       }
   }
   if(cnt==1)
   printf("graph is connected\n");
   else
   printf("graph is disconnected with %d components\n",cnt);
   printf("topological order\n");
   while(wow>0)
   {
       printf("%d ",out[--wow]);
   }
   
   printf("\ncalling vertex removal metod\n");
   for(i=0;i<n;i++)
   v[i]=0;
   vertexrml(n,a,in,v);
  
   return 0;
}

void dfs(int a[10][10],int n,int v[10],int src)
{
    //stack[++top]=src;
    v[src]=1;
    int i;
    for(i=0;i<n;i++)
    {
        if(a[src][i]==1 && v[i]==0)
        {
            printf("%d ",i);
            dfs(a,n,v,i);
        }
    }
    //m=stack[top--];
    out[wow++]=src;
}

void vertexrml(int n,int a[10][10],int in[10],int v[10])
{
    printf("topological order\n");
    int node;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(in[j]==0 && v[j]==0)
            {
                node=j;
                printf("%d ",node);
                v[node]=1;
                break;
            }
        }
        for(j=0;j<n;j++)
        {
            if(a[node][j]==1)
            in[j]--;
        }
    }
}
