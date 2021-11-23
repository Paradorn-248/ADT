#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int fac(int n)
{
    if (n==1||n==0)
    {
        return 1;
    }
    else
    {
        return n * fac(n-1);
    }
}

int main()
{
    int amount,a,i;
    scanf("%d",&amount);
    for(i=0;i<amount;i++)
    {
        int k,j;
        scanf("%d",&a);
        for(k=a-1;k>=0;k--)
        {
            int sum = 0,len=0;  
            int tmp = k;      
            while (tmp!=0)
            {
                tmp /= 10;
                len += 1;
            }
            // printf("%d\n",len);
            tmp = k;
            for(j=0;j<len;j++)
            {
                sum += fac(tmp%10);
                tmp /= 10;
            }
            if (sum == k)
            {
                printf("%d\n",k);
                break ;
            }
        }
    } 
    return 0;
}