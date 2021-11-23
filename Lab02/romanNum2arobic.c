#include<stdio.h>
#include<string.h>

int main()
{
    char roman[4000];
    char *sign[] = {"I","V","X","L","C","D","M"};
    int value[] = {1,5,10,50,100,500,1000},res=0;
    int i,j,n;
    scanf("%d",&n);
    for(j=0;j<n;j++)
    {
        scanf(" %s",roman);
        int res = 0;
        for(i=0;i<strlen(roman);i++)
        {
            if (roman[i]=='I')
            {   
                if (roman[i+1]!='V')
                {
                    res += 1;
                }
                else if(roman[i+1] == 'V')
                {
                    res -= 1;
                }
            }
            if (roman[i]=='V')
            {
                if (roman[i+1]!='X')
                {
                    res += 5;
                }
                else if(roman[i+1] == 'X')
                {
                    res -= 5;
                }
            }
            if (roman[i]=='X')
            {
                if (roman[i+1]!='L'&&roman[i+1]!='C')
                {
                    res += 10;
                }
                else if(roman[i+1] == 'L'||roman[i+1]=='C')
                {
                    res -= 10;
                }
            }
            if (roman[i]=='L')
            {
                if (roman[i+1]!='C')
                {
                    res += 50;
                }
                else if(roman[i+1] == 'C')
                {
                    res -= 50;
                }
            }        
            if (roman[i]=='C')
            {
                if (roman[i+1]!='D')
                {
                    res += 100;
                }
                else if(roman[i+1] == 'D')
                {
                    res -= 100;
                }
            }
            if (roman[i]=='D')
            {
                if (roman[i+1]!='M')
                {
                    res += 500;
                }
                else if(roman[i+1] == 'M')
                {
                    res -= 500;
                }
            }  
            if (roman[i]=='M')
            {
                res += 1000;
            }
        }

        printf("%d\n",res);
    }
    

    return 0;
}