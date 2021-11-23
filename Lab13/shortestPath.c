#include<stdio.h>

int min(int a,int b)
{
    if(a<b)
        return a;
    else
        return b;
}

int main()
{
    int n,m,p,i,j,k,u,v,w;
    scanf("%d %d %d",&n,&m,&p);
    int graph[n+1][n+1];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
                graph[i][j] = 0;
            else
                graph[i][j] = 1e7;
        }
    }
    for(i=0;i<m;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        graph[u][v] = w;
        graph[v][u] = w;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                graph[j][k]=min(graph[j][k],graph[j][i]+graph[i][k]);
            }
        }
    }   
    for(i=0;i<p;i++)
    {
        scanf("%d %d",&u,&v);
        if(graph[u][v]==1e7)
            printf("-1\n");
        else
            printf("%d\n",graph[u][v]);
    }
}