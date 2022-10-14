#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int table[1000];

void shifttable(char p[],int m)
{
    int i,j;
    for(i=0;i<1000;i++)
    {
        table[i]=m;
    }
    for(i=0;i<=m-2;i++)
    {
        table[p[i]]=m-1-i;
    }
}

int horsepool(char p[],char t[],int m)
{
    int i,j,n,k;
    n=strlen(t);
    k=0;
    i=m-1;
    while(i<=n-1)
    {
        while(k<=m-1 && t[i-k]==p[m-1-k])
        k++;
        if(k==m)
        return i-m+1;
        else
        i=i+table[t[i]];
    }
    return -1;
}

int main()
{
    int ind;
    char p[20],t[100];
    printf("enter the text\n");
    scanf("%[^\n]s]",t);
    printf("enter the pattern\n");
    scanf("\n");
    scanf("%[^\n]s",p);
    int m=strlen(p);
    shifttable(p,m);
    ind=horsepool(p,t,m);
    if(ind==-1)
    printf("pattern not found\n");
    else
    printf("pattern found at %dth index\n",ind);
    return 0;
}















