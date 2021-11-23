#include<stdio.h>

int main()
{
    float ln,lo,c,n;
    scanf("%f%f%f%f",&ln,&lo,&c,&n);
    int price1 = c/(((lo-ln)*n)/1000);
    float price2 = c/(((lo-ln)*n)/1000);
    if (price1-price2 == 0)
        printf("%d",price1);
    else
        printf("%d",price1+1);
    // printf("%d",(int)150/0.182);
}

