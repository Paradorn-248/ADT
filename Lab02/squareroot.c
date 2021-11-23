#include<stdio.h>
#include<math.h>

int main()
{
    double dif=0.2,g0,N,tmp;
    scanf("%lf %lf",&N,&g0);
    while(dif>=1e-10)
    {
        tmp = g0;
        g0 = 0.5*(g0+N/g0);
        dif = fabs(tmp - g0);
        printf("%.10f %.10f %.10f\n",g0,tmp,dif);
    }
    printf("%.10f",g0);
}