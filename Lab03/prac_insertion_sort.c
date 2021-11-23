#include<stdio.h>

void swap(int *a,int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int arr[] = {1,5,2,14,10,2,12};
    int len = sizeof(arr)/sizeof(arr[0]),tmp;
    for(int i=1;i<len;i++)
    {
        for(int j=i;j>=0;j--)
        {
            if(arr[j]<=arr[j-1])
            {
                swap(&arr[j],&arr[j-1]);
            }
            else
            {
                break;
            }
        }
    }

    for(int i = 0;i<len;i++)
    {
        printf("%d ",arr[i]);
    }
}