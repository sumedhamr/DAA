#include <stdio.h>
#include <stdlib.h>
void dijs(int n,int src,int cost[20][20],int dist[10],int pred[10]);

int main()
{
    int n,i,j,cost[20][20],src,dist[10],pred[10];
    printf("enter the no of verticies\n");
    scanf("%d",&n);
    printf("enter the cost matrix\n");
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
        scanf("%d",&cost[i][j]);
        if(cost[i][j]==0)
        cost[i][j]=999;
    }
    printf("enter the source vertex\n");
    scanf("%d",&src);
    dijs(n,src,cost,dist,pred);
    printf("shortest paths:\n");
    for(i=0;i<n;i++)
    {
        if(i!=src)
        {
            printf("shortest dist of vertex %d = %d\n",i,dist[i]);
            printf("path is :\n");
            printf("%d",i);
            j=i;
            while(j!=src)
            {
                j=pred[j];
                printf("<-%d ",j);
            }
        }
    }
    return 0;
}

void dijs(int n,int src,int cost[20][20],int dist[10],int pred[10])
{
    int v,visited[10],i,j,min,cnt;
    for(i=0;i<n;i++)
    {
        visited[i]=0;
        dist[i]=cost[src][i];
        if(dist[i]!=999)
        pred[i]=src;
    }
    visited[src]=1;
    dist[src]=0;
    pred[src]=-1;
    cnt=1;
    while(cnt<n)
    {
        min=999;
        for(i=0;i<n;i++)
        {
            
            if(!visited[i]&&dist[i]<min)
            {
                min=dist[i];
                v=i;
            }
        }
        visited[v]=1;
        cnt++;
        for(i=0;i<n;i++)
        {
            if(!visited[i]&&dist[i]>dist[v]+cost[v][i])
            {
                dist[i]=dist[v]+cost[v][i];
                pred[i]=v;
            }
        }
    }
}























