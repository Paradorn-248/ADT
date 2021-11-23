#include<stdio.h>
#include<math.h>

int main()
{
    /*
        4
      3   1
        2
    */
    int n,i,dir=1;
    int x=0,y=0;
    char move[100000];
    scanf("%d",&n);
    scanf(" %s",move);
    for(i=0;i<n;i++)
    {
        if(move[i] == 'R')
        {
            dir += 1;
            if (dir > 4)
            {
                dir %= 4;
            }
        }
        if(move[i] == 'L')
        {
            dir -= 1;
            if (dir < 1)
            {
                dir = 4;
            }
        }
    
        if (move[i]=='F')
        {
            if (dir == 1)
            {
                x += 1;
            }
            if(dir == 2)
            {
                y += 1;
            }
            if(dir == 3)
            {
                x-=1;
            }
            if (dir == 4)
            {
                y -= 1;
            }
        }
    }
    printf("%.4f\n",sqrt(x*x+y*y));
    return 0;
}
