#include<stdio.h>

void swap(int *a,int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{    
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    // for(int i=1;i<n;i++)
    // {   
    //     int tmp = i;
    //     while(1)
    //     {
    //         if(a[tmp]<=a[tmp-1])
    //         {
    //             swap(&a[tmp],&a[tmp-1]);    
    //             tmp -= 1;
    //         }
    //         else
    //         {
    //             break;
    //         }                
    //     }            
    //     for(int i=0;i<n;i++)
    //     {
    //         printf("%d ",a[i]);
    //     }
    //     printf("\n");
    // }

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
        for(int i=0;i<n;i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
    }
}