#include <stdio.h>
#include <stdlib.h>

int check(char str[], char sub[], int lensub, int i, int n)
{
    int j = 0, wcnt = 0;
    for (j = 0; j < lensub; j++)
    {
        //printf("%c %c %d ",str[i+j],sub[j],i+j);
        if (str[i + j] != sub[j])
        {
            wcnt++;
        }
    }
    if (wcnt > n)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    int x, i = 0, j = 0, len, lensub, n;
    scanf("%d %d %d", &len, &lensub, &n);
    char str[len + 1], sub[lensub + 1];
    scanf("%s", str);
    scanf("%s", sub);

    while (1)
    {
        //printf("%d %d %d\n",i,len,len-lensub);
        x = check(str, sub, lensub, i, n);
        if (x)
        {
            for (j = 0; j < lensub; j++)
            {
                if (str[i + j] != sub[j])
                {
                    str[i + j] = '?';
                }
            }
            printf("[");
            for (j = i; j < i + lensub; j++)
            {
                printf("%c", str[j]);
            }
            printf("]");
            i += lensub;
        }
        else
        {
            printf("%c", str[i]);
            i++;
        }
        if (i > len - lensub)
        {
            for (j = i; j <= len - 1; j++)
            {
                printf("%c", str[j]);
            }
            break;
        }
    }
    printf("\n");
}