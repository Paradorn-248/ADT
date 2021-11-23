#include<stdio.h>

int main()
{
    // define the direction vectors for N,S,E,W
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,1,-1};
    int R,C;
    scanf("%d%d",&R,&C);
    for (int i=0;i<4;i++)
    {
        rr = r + dr[i];
        cc = c + dc[i];
        if (rr<0||cc<0||rr>=R||cc>=C) continue;
    }   
}