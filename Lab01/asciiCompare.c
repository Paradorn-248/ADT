#include<stdio.h>
#include<stdlib.h>

int main()
{
    char a,b;
    scanf("%c %c",&a,&b);
    int x;
    x = (int)a-(int)b;
    a = atoi(a);
    printf("%d",x);
}