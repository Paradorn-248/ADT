#include <stdio.h>
#include <math.h>

int main()
{
    int m, n, i, j, k, p, chk, nub = 0, z, x;
    scanf("%d %d", &m, &n);
    int map[m][n];
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            map[i][j] = 0;
        }
    }
    int loop = sqrt(m);
    for (i = loop; i >= 0; i--)
    {   
        int a = pow(2,i);
        int l_wid = m - a + 1;
        int l_len = n - a + 1;
        for (k = 0; k < l_wid; k++)
        {
            for (p = 0; p < l_len; p++)
            {   
                chk = 0;
                for (z = k; z < k+a; z++)
                    for (x = p; x < p+a; x++)
                        if (map[z][x] == 0)
                        {
                            chk += 1;
                        }
                // printf("%d\n", chk);
                if (chk == a * a)
                {
                    for (int z = k; z < k+a; z++)
                    {
                        for (int x = p; x < p+a; x++)
                        {
                            map[z][x] = 1;
                        }
                    }
                    nub += 1;
                }
            }
        }
        // printf("---------------------------\n");
        // for (int ii = 0; ii < m; ii++)
        // {
        //     for (int jj = 0; jj < n; jj++)
        //     {
        //         printf("%d ", map[ii][jj]);
        //     }
        //     printf("\n");
        // }
    }
    printf("%d", nub);
}