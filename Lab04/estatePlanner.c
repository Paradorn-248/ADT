#include <stdio.h>
#include <math.h>

int main()
{
    int m, n, i;
    int res = 0;
    int area = m * n;
    scanf("%d %d", &m, &n);
    int loop = log2(m);
    for (i = 0; i <= loop; i++)
    {
        int now_shape = pow(2,i);
        int next_shape = pow(2,i+1);
        int b = ((m / now_shape) * (n/now_shape))* pow(2,2*i);
        int c = ((m / next_shape)) * (n/next_shape)* pow(2,2*(i+1));
        int d = pow(2,i)*pow(2,i);
        res += (b - c) / d;
    }

    printf("%d", res);
}


// O(log(m))