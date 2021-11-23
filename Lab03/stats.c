#include<stdio.h>
#include<stdlib.h>

void findstats(int *nums,int n,int *maxi,int *mini,double *avg)
{
    int i,max=0,min=101;
    double sum =0;
    for(i = 0;i<n;i++)
    {
        sum = sum + *(nums + i);
        if(*(nums+i)>=max)
            max = *(nums+i);
        if(*(nums+i)<=min)
            min = *(nums+i);
    }
    *maxi = max;
    *mini = min;
    *avg = sum/n;
}

int main()
{
    int n,i,maxi,mini;
    double avg;
    int *nums;

    scanf("%d",&n);
    nums = (int*) malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        scanf("%d",nums+i);
    }
    findstats(nums,n,&maxi,&mini,&avg);
    printf("%.2f %d %d",avg,maxi,mini);
    return 0;
}