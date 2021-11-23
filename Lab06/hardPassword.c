#include<stdio.h>
#include<string.h>

int main()
{
    char pass[1000000];
    scanf("%s",pass);
    int i=0;
    int len = strlen(pass)-2;
    while(pass[i]!='x')
    {
        if(pass[i]!=pass[len])
        {
            printf("0");
            return 0;
        }
        len--;
        i++;
    }
    printf("1");
    return 0;
}