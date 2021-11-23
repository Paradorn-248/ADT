#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void swap(char *a,char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void insertion_sort(int n,char a[])
{    
    for(int i=1;i<n;i++)
    {
        for(int j=i;j>=1;j--)
        {
            if(a[j]<=a[j-1])
            {
                swap(&a[j],&a[j-1]);
            }
            else
            {
                break;
            }
        }    
    }
}

int main()
{
    int m,n,i,j;
    scanf("%d %d",&m,&n);
    char sorted[m][51],chk[51];
    char text[m][51];
    for(i=0;i<m;i++)
    {
        scanf("%s",sorted[i]);
        strcpy(text[i],sorted[i]);
        insertion_sort(strlen(sorted[i]),sorted[i]);
    }
    for(i=0;i<n;i++)
    {
        scanf("%s",chk);
        insertion_sort(strlen(chk),chk);
        for(j=0;j<m;j++)
        {
            if(strcmp(sorted[j],chk)==0)
            {
                printf("%s ",text[j]);
            }
            
        }
        printf("\n");
    }
}