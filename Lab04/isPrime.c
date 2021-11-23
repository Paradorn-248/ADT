#include<stdio.h>
#include<math.h>

int main()
{
    int n,i,chk=1;
    scanf("%d",&n);
    if(n==0||n==1)
    {
        printf("0");
        return 0;
    }
    int loop = sqrt(n);
    for(i=2;i<loop;i++)
    {
        if(n%i==0)
        {
            chk = 0;
        }
    }
    if(chk==0)
    {
        printf("0");
    }
    else
    {
        printf("1");
    }
}

// O(sqrt(n))