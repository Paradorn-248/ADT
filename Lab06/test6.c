#include<stdio.h>
#include<math.h>

int fibo(int a)
{
    if(a==1)
    {
        return 1;
    }
    else if(a==0)
    {
        return 0;
    }
    else 
    {
        return fibo(a-1)+fibo(a-2);
    }
}

int serie(int a)
{
    if(a==1)
        return 1;
    else 
    return a+serie(a-1);
}

int add()
{
    static int x = 0;
    return ++x;
}

long int fac(int a)
{
    if(a==1||a==0)
    {
        return 1;
    }
    else 
    {
        return a*fac(a-1);
    }
}

float money(int start,int n)
{
    if(n==0)
        return start;
    else 
        return 1.05*money(start,n-1);
}
double dif=1;
void squareroot(double now,double n)
{
    double ans;
    if(dif<1e-10)
    {
        printf("%.10lf\n",now);
        return;
    }
    ans = 0.5*(now+n/now);
    dif = fabs(ans-now);
    printf("%.10lf %.10lf %.10lf\n",ans,now,dif);
    squareroot(ans,n);
}


int main()
{
    int a = fibo(4);
    printf("%d\n",a);
    long int b = 5;
    printf("%ld\n",fac(b));
    printf("%d\n",serie(4));
    printf("%f\n",money(100,1));
    squareroot(1000,100);
    
    // printf("%d",add());
}