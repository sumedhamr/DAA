
#include <stdio.h>
#include<stdlib.h>

void dfs(int a[10][10],int n,int v[10],int src);
void bfs(int a[10][10],int n,int v[10],int src);

int main()
{
   int a[10][10],v[10],n,i,j,source;
   int cnt=0;
   printf("enter the no of nodes\n");
   scanf("%d",&n);
   printf("read the adj matrix\n");
   for(i=0;i<n;i++)
   for(j=0;j<n;j++)
   scanf("%d",&a[i][j]);
   
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
   
   printf("calling bfs\n");
   for(i=0;i<n;i++)
   v[i]=0;
   cnt=0;
   for(i=0;i<n;i++)
   {
       if(v[i]==0)
       {
        printf("%d ",i);
           
           bfs(a,n,v,i);
           cnt++;
       }
   }
   if(cnt==1)
   printf("graph is connected\n");
   else
   printf("graph is disconnected with %d components\n",cnt);
   
   return 0;
}

void dfs(int a[10][10],int n,int v[10],int src)
{
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
}

void bfs(int a[10][10],int n,int v[10],int src)
{
    v[src]=1;
    int q[10];
    int rear=-1;
    int front=0;
    int node,i;
    
    q[++rear]=src;
    while(front<=rear)
    {
    
        node=q[front++];
  //    printf("%d ",node);
        for(i=0;i<n;i++)
        {
            if(a[node][i]==1 && v[i]==0)
            {
                printf("%d ",i);
                v[i]=1;
                q[++rear]=i;
            }
        }
    }
}
















