#include <stdio.h>
#include<string.h>

int main()
{
    char *months[] = {" ", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char *weak[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    int year, month;
    printf("Enter year: ");
    scanf("%d", &year);
    printf("Enter month: ");
    scanf("%d", &month);
    printf("====================\n%s %d\nSun Mon Tue Wed Thu Fri Sat\n", months[month], year);
    int i;
    // char countday[4] = "Mon"; //สมมติtestcaseแรก
    
    //หาว่าเดือนนั้นเริ่มที่วันไหน
    int countday = 1,sum_day=1;
    for(i=1990;i<year;i++)
    {
        if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
            sum_day += 366;
        else
            sum_day += 365;

    }        
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        day[2] = 29;
    else
        day[2] = 28;
    for(i=1;i<month;i++)
    {
        sum_day += day[i];
    } 
    countday = sum_day % 7; 
    // printf("%d %d\n",sum_day,countday);
   
    // print calendar
    int k;
    for (k=0;k<countday;k++)
    {
        printf("    ");
    }
    for (i = 1; i <= day[month]; i++)
    {
        
        if (strcmp(weak[countday],"Sat")==0)
        {
            printf("%3d", i);
            printf("\n");
            countday = 0;
        }
        else
        {
            printf("%3d ", i);
            countday += 1;
        }
    }
    // for (i = 1; i <= day[month]; i++)
    //     printf("%d ",strcmp(weak[countday],"Sat"));
    return 0;
}