#include <stdio.h>

int main()
{
    char A[10];
    int day, month, year,res=0,i;
    for(i=0;i<10;i++)
        scanf("%c",&A[i]);
    day = (((int)A[0]-48)*10)+(int)A[1]-48;
    month = (((int)A[3]-48)*10)+(int)A[4]-48;
    year = ((((int)A[6]-48)*1000)+(((int)A[7]-48)*100)+(((int)A[8]-48)*10)+(int)A[9]-48);
    printf("%d %d %d %d\n",day,month,year,day+year+month);
    
    int mm[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        mm[1] = 29;
    for(i=2018;i<year-1;i++)
    {
        if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            res += 366;
        else 
            res += 365; 
    }
    for (i = 0; i < month - 1; i++)
        res += mm[i];
    printf("%d", res+day);
    return 0;
}