#include <stdio.h>

int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return fib(n - 2) + fib(n - 1);
}

void countdown(int n)
{
    if (n == 0)
    {
        printf("0");
        return;
    }
    printf("%d ", n);
    countdown(n - 1);
}
void countdown2(int n)
{
    printf("%d ", n);
    if (n == 0)
    {
        return;
    }
    countdown2(n - 1);
}
void countdown3(int n)
{
    if (n == -1)
    {
        return;
    }    
    printf("%d ", n);
    countdown3(n - 1);
}

void countup(int now,int end)
{
    printf("%d ",now);
    if(now!=end)
    {
        countup(now+1,end);
    }
}

void countup2(int now,int end)
{
    if(now==end+1)
    {
        return ;
    }
    printf("%d ",now);
    countup2(now+1,end);
}
void countup3(int now,int end)
{
    printf("%d ",now);
    if(now==end)
    {
        return ;
    }
    countup3(now+1,end);
}

void toh(int n,char src,char dest,char aux) //toh(จำนวน,เสาเริ่ม,เสาเป้าหมาย,เสาช่วย)
{
    if(n==1)
    {
        printf("move %c to %c\n",src,dest);
        return;
    }
    toh(n-1,src,aux,dest); //ย้ายn-1ก้อนจากsrcไปauxโดยให้destช่วย
    toh(1,src,dest,aux); //ย้าย1ก้อนที่เหลือจากsrcไปdestโดยให้auxช่วย
    toh(n-1,aux,dest,src); //ย้ายn-1ก้อนจากauxไปdestโดยให้srcช่วย
}

int main()
{
    printf("%d\n", factorial(6));
    printf("%d\n", fib(6));
    ///////////////////////////////////
    countdown(6);
    printf("\n");
    countdown2(6);
    printf("\n");
    countdown3(6);
    printf("\n");
    //////////////////////////////////
    countup(0,6);
    printf("\n");
    countup2(0,6);
    printf("\n");
    countup3(0,6);
    printf("\n");
    //////////////////////////////////
    toh(5,'A','C','B');
}