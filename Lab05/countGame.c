#include<stdio.h>

int check(int count,int k)
{
    if(count%k==0)
    {
        return 1;
    }
    while(count!=0)
    {
        if(count%10==k)
        {
            return 1;
        }
        count/=10;
    }
    return 0;
}

int main()
{
    int n,k,i,loop=0,count=1;
    scanf("%d %d",&n,&k);
    int remain = n;
    int limit[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&limit[i]);
    }

    while(remain!=1)
    {
        if(limit[loop]<0)
        {
            if(loop+1==n)
                loop = 0;
            else
                loop++;
            continue;
        }
        else if(check(count,k)==1)
        {
            limit[loop] -= 1;
            if(limit[loop]<0)
            {
                remain-=1;
            }
        }
        if(loop+1==n)
        {
            loop = 0;
            count++;
            continue;
        }
        loop++;
        count++;
    }

    for(i=0;i<n;i++)
    {
        if(limit[i]>=0)
        {
            printf("%d",i+1);
            break;
        }
    }
    return 0;
}