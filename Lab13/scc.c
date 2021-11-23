#include<stdio.h>
int graph[1000][1000],in[1000],out[1000],visit[1000];
int grapht[1000][1000],visit2[1000],arans[1000],tmpans[1000],size_ans=0,size_tmp=0;
int count=1,n,pos=0;

void swap(int *a,int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void dfs(int now)
{
    // printf("%d\n",now);
    int i; 
    in[now] = count;
    count++;
    visit[now]=1;
    for(i=0;i<n;i++)
    {
            // printf("++\n");
        if(visit[i]==0&&graph[now][i]==1)
        {
            // printf("%d\n",i);
            dfs(i);
        }
    }
    out[now] = count;
    count++;
}

void dfs2(int now)
{
    int i; 
    visit2[now]=1;            
    tmpans[size_tmp] = now;
    size_tmp++;
    for(i=0;i<n;i++)
    {
        if(visit2[i]==0&&grapht[now][i]==1)
        {
            dfs2(i);
        }
    }
}

int ind_max_out(int out[])
{
    int i,max=0,ind=0;
    for(i=0;i<n;i++)
    {
        if(max<out[i]&&visit2[i]==0)
        {
            max = out[i];
            ind = i;
        }       
    }
    return ind;
}

int main()
{
    int m,u,v,i,j;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&u,&v);
        graph[u][v] = 1;
        grapht[v][u] = 1;
    }
    for(i=0;i<n;i++) //บางทีกราฟมันแยก2กลุ่ม ถ้าเราไม่วนloop อาจจะไม่เจอnodeที่ไม่เจอ
    {
        if(visit[i]==0)
            dfs(i);
    }
    // for(i=0;i<n;i++)
    // {
    //     printf("%d %d\n",in[i],out[i]);
    // }
    int ind;
    for(i=0;i<n;i++)
    {
        ind = ind_max_out(out);
        if(visit2[ind] == 0)
        {
            // printf("ind = %d\n",ind);
            dfs2(ind);
            if(size_ans<size_tmp)
            {
                size_ans = size_tmp;
                for(j=0;j<size_ans;j++)
                {
                    arans[j] = tmpans[j];
                }
            }
            size_tmp = 0;
        }    
    }

    for(int i=1;i<size_ans;i++)
    {
        for(int j=i;j>=1;j--)
        {
            if(arans[j]<=arans[j-1])
            {
                swap(&arans[j],&arans[j-1]);
            }
            else
            {
                break;
            }
        }
    }
    for(i=0;i<size_ans;i++)
    {
        printf("%d ",arans[i]);
    }
}