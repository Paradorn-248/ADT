#include <stdio.h>

int store[100],n,m,graph[100][100];

int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int is_clique(int b)
{
    for (int i=1;i<b;i++) 
    {
        for (int j=i+1;j<b;j++)
            if (graph[store[i]][store[j]] == 0)
                return 0;
    }
    return 1;
}

int maxCliques(int i, int l)
{
    int maxcl = 0;
    for (int j=i+1;j<=n;j++) 
    {
        store[l] = j;
        if (is_clique(l + 1))
        {
            maxcl = max(maxcl,l);
            maxcl = max(maxcl,maxCliques(j,l+1));
        }
    }
    return maxcl;
}

int main()
{
    scanf("%d %d",&n,&m);
    for (int i=0;i<m;i++) 
    {
        int u,v;
        scanf("%d %d",&u,&v);
        graph[u+1][v+1] = 1;
        graph[v+1][u+1] = 1;
    }
    printf("%d",maxCliques(0, 1));
    return 0;
}