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
    int len = sizeof(arr)/sizeof(arr[0]);
    int index;
    for(int i=0;i<len;i++)
    {
        index = i;
        for(int j=i;j<len;j++)
        {
            if(arr[index]>arr[j])
            {
                index = j;
            }
        }
        swap(&arr[index],&arr[i]);
    }
    for(int i = 0;i<len;i++)
    {
        printf("%d ",arr[i]);
    }

}