#include <stdio.h>

char arr[101][101];
int jue = 0, n;
int visit[101][101];

void traversemaze(int row, int col)
{
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    int i;
    if (row == -1 || col == -1 || row == n || col == n)
        return;
    if (arr[row][col] == '#')
        return;
    if (visit[row][col] == 1)
        return;
    visit[row][col] = 1;
    if (arr[row][col] == 'G')
    {
        jue = 1;
        return;
    }
    for (i = 0; i < 4; i++)
    {
        traversemaze(row + dr[i], col + dc[i]);
        // for (int j = 0; j < n; j++)
        // {
        //     for (int k = 0; k < n; k++)
        //         printf("%d ", visit[j][k]);
        //     printf("\n");
        // }
        // printf("\n");
        if (jue)
        {
            arr[row][col] = '.';
            return;
        }
    }
}

int main()
{
    int j, i, sr, sc;
    scanf("%d ", &n);
    for (i = 0; i < n; i++)
    {
        fgets(arr[i], 100, stdin);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] == 'S')
            {
                sr = i;
                sc = j;
            }
        }
    }
    traversemaze(sr, sc);
    arr[sr][sc] = 'S';
    for (j = 0; j < n; j++)
    {
        printf("%s", arr[j]);
    }
    return 0;
}