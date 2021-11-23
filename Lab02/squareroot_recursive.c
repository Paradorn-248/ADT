#include <stdio.h>
#include <math.h>

void squareroot(double now,double n)
{
    double ans;
    static double dif = 1;
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
    double n,g;
    scanf("%lf %lf",&n,&g);
    squareroot(g,n);
}