#include <stdio.h>
#include <string.h>

int odd(int n)
{
    if (n==1)
    {
        return 1;
    }
    else 
    {
        return 2+odd(n-1);
    }
}

int odd2(int n)
{
    // printf("%d ",a);
    if (n==1)
    {
        // printf("%d ",n);
        return 1;
    }
    else
    {
        // a
        return 2+odd2(n-1);
    }

}


int main()
{   
    int a = odd2(6);
    printf("%d ",a);
}
 

