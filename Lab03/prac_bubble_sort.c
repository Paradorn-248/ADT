#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort(int arr[],int len)
{
    int check;
    printf("%d\n",len);
    while (check != 0)
    {
        check = 0;
        for (int i = 0; i < len-1; i++)
        {
            if(arr[i]>arr[i+1])
            {
                swap(&arr[i],&arr[i+1]);
                check = 1;
            }
        }
    }
}


int main()
{
    int arr[] = {1, 5, 2, 14, 10, 2, 12};
    int len = sizeof(arr) / sizeof(arr[0]), check;
    sort(arr,len);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
}