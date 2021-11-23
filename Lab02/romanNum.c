#include<stdio.h>

int main()
{
    int num,n,i,j=0;
    char *sign[] = {"M", "CM", "D", "CD","C", "XC", "L", "XL","X", "IX", "V", "IV","I"};
    int value[] = {1000, 900, 500,   400,100,  90,   50,  40,  10,   9,   5,    4,  1};
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        while(num!=0)
        {   
            if (num >= value[j])
            {
                printf("%s",sign[j]);
                num -= value[j];
            }
            else
            {
                j += 1;
            }
        }
        j=0;
        printf("\n");
    }
    return 0;
}