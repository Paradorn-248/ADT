#include <stdio.h>
#include <stdlib.h>

typedef struct heap {
    int *data;
    int last_index;
} heap_t;

heap_t *init_heap(int m)
{
    heap_t *h = (heap_t *)malloc(sizeof(heap_t));
    h->last_index = 0;
    h->data = (int *)malloc(sizeof(int)*(m+1));
    return h;
}

void swap(heap_t *h,int a,int b)
{
    int tmp = h->data[a];
    h->data[a] = h->data[b];
    h->data[b] = tmp;
}

void insert(heap_t *h,int data)
{
    h->last_index += 1;
    h->data[h->last_index] = -data;
    int n = h->last_index/2;
    int chk = h->last_index;
    while (n>0)
    {
        if(h->data[chk]<h->data[n])
        {
            swap(h,chk,n);
            chk = n;
        }
        else
            break;
        n = n/2;
    }
}

void bfs(heap_t *h)
{
    int i;
    for(i=1;i<=h->last_index;i++)
    {
        printf("%d ",-h->data[i]);
    }
    printf("\n");
}

void delete_max(heap_t *h)
{    
    if (h->last_index<=0)
        return;
    h->data[1] = h->data[h->last_index];
    h->last_index--;
    int n = 1;
    while (2*n<h->last_index)
    {
        if(h->data[n]>h->data[n*2]&&h->data[n*2]<h->data[n*2+1])
        {
            swap(h,n,n*2);
            n = n*2;
        }
        else if(h->data[n]>h->data[n*2+1]&&h->data[n*2]>h->data[n*2+1])
        {
            swap(h,n,n*2+1);
            n = n*2+1;
        }
        else
            break;
    }
}

int find_max(heap_t *h)
{   
    if (h->last_index <= 0)
        return -1;
    return -h->data[1];
}

void update_key(heap_t *h,int old_key,int new_key)
{
    int i,n,n2;
    for(i=1;i<=h->last_index;i++)
    {
        if(h->data[i] == -old_key)
        {
            h->data[i] = -new_key;
            n = i;
            n2 = i;
            break;
        }
    }
    while (2*n<=h->last_index)
    {
        if(h->data[n]>h->data[n*2]&&h->data[n*2]<=h->data[n*2+1])
        {
            swap(h,n,n*2);
            n = n*2;
        }
        else if(h->data[n]>h->data[n*2+1]&&h->data[n*2]>=h->data[n*2+1])
        {
            swap(h,n,n*2+1);
            n = n*2+1;
        }
        else
            break;
    }
    while (n2/2>0)
    {
        if(h->data[n2]<h->data[n2/2])
        {
            swap(h,n2,n2/2);
        }
        else
            break;
        n2 = n2/2;
    }
}

int main(void) {
    heap_t *max_heap = NULL;
    int    m, n, i;
    int    command, data;
    int    old_key, new_key;

    scanf("%d %d", &m, &n);
    max_heap = init_heap(m);
    for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch (command) {
        case 1:
            scanf("%d", &data);
            insert(max_heap, data);
            break;
        case 2:
            delete_max(max_heap);
            break;
        case 3:
            printf("%d\n", find_max(max_heap));
            break;
        case 4:
            scanf("%d %d", &old_key, &new_key);
            update_key(max_heap, old_key,
                    new_key);
            break;
        case 5:
            bfs(max_heap);
            break;
    }
    }
    return 0;
}