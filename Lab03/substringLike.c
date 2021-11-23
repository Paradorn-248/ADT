#include <stdio.h>

int main()
{
    int m, p, n, i=0, j, miss;
    scanf("%d %d %d", &m, &p, &n);
    char sub[p+1], string[m+1];
    scanf(" %s", string);
    scanf(" %s", sub);
    while (1)
    {
        miss = 0;
        for (j = 0; j < p; j++)
        {
            if (string[i + j] != sub[j])
            {
                miss += 1;
            }
        }  
        if (miss <= n)
        {
            printf("[");
            for (j = 0; j < p; j++)
            {
                if (string[i + j] == sub[j])
                {
                    printf("%c", sub[j]);
                }
                else
                {
                    printf("?");
                }
            }
            printf("]");
            i += p;
        }
        else
        {
            printf("%c", string[i]);
            i++;
        }        
        if (i > m - p)
        {
            for (j = i; j <= m - 1; j++)
            {
                printf("%c", string[j]);
            }
            break;
        }
    }
    return 0;
}
