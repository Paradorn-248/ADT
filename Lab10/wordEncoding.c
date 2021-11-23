#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int freq;
    char word[20];
    struct node *left;
    struct node *right;
} tree_t;

typedef struct heap {
    tree_t **data;
    int last_index;
} heap_t;

heap_t *init_heap(int m)
{
    heap_t *h = (heap_t *)malloc(sizeof(heap_t));
    h->last_index = 0;
    h->data = (tree_t **)malloc(sizeof(tree_t)*(m+1));
    return h;
}

tree_t *create(int afreq,char aword[])
{ 
    tree_t *node = (tree_t *)malloc(sizeof(tree_t));
    node->freq = afreq;
    strcpy(node->word,aword);
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(heap_t *h,int afreq,char aword[])
{
    h->last_index += 1;
    int n = h->last_index/2;
    int chk = h->last_index;
    h->data[chk] = create(afreq,aword);
    tree_t *tmp;
    while (n>0)
    {
        if(h->data[chk]->freq<h->data[n]->freq)
        {
            tmp = h->data[chk];
            h->data[chk] = h->data[n];
            h->data[n] = tmp;
            chk = n;
        }
        else
            break;
        n = n/2;
    }
}

void insert2(heap_t *h,tree_t *root)
{
    h->last_index += 1;
    int n = h->last_index/2;
    int chk = h->last_index;
    h->data[chk] = root;
    tree_t *tmp;
    while (n>0)
    {
        if(h->data[chk]->freq<h->data[n]->freq)
        {
            tmp = h->data[chk];
            h->data[chk] = h->data[n];
            h->data[n] = tmp;
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
        printf("%d ",h->data[i]->freq);
    }
    printf("\n");
}
// /*
tree_t *delete_max(heap_t *h)
{    
    if (h->last_index<=0)
        return NULL;
    tree_t *re = h->data[1];
    h->data[1] = h->data[h->last_index];
    h->last_index--;
    int n = 1;
    tree_t *tmp;
    while (2*n<=h->last_index)
    {
        // printf("d\n");
        // printf("%d %d %d\n",n,n*2,n*2+1);
        if(h->data[n]->freq>h->data[n*2]->freq&&h->data[n*2]->freq<=h->data[n*2+1]->freq)
        {
            // swap(h,n,n*2);
            // printf("e\n");

            tmp = h->data[n];
            h->data[n] = h->data[n*2];
            h->data[n*2] = tmp;
            n = n*2;
        }
        else if(h->data[n]->freq>h->data[n*2+1]->freq&&h->data[n*2]->freq>=h->data[n*2+1]->freq)
        {
            // swap(h,n,n*2+1);
        // printf("f\n");

            tmp = h->data[n];
            h->data[n] = h->data[n*2+1];
            h->data[n*2+1] = tmp;
            n = n*2+1;
        }
        else
            break;
    }
    // printf("re\n");
    return re;
}
// */

void dfs(tree_t* t,int arr[],int p)
{
    int i;
    char a[10] = "";
    if (t==NULL) return;
    if(strcmp(t->word,a)){
        printf("%s: ",t->word);
        for(i=0;i<p;i++){
            printf("%d",arr[i]);
        }
        printf("\n");
    }
    arr[p]=0;
    arr[p+1]=0;
    dfs(t->left,arr,p+1);
    arr[p]=1;
    arr[p+1]=1;
    dfs(t->right,arr,p+1);
}

tree_t *combt(tree_t *t1,tree_t *t2)
{
    char a[20] = "";
    tree_t *root = create(t1->freq+t2->freq,a);
    // printf("%d\n",t1->freq+t2->freq);
    root->left = t1;
    root->right = t2;
    return root;
}

int main()
{
    int n,f,i;
    scanf("%d ",&n);
    char w[n][20];
    heap_t *h = init_heap(n);
    for (i=0; i<n; i++) 
    {
        scanf("%s %d",w[i],&f);
        insert(h,f,w[i]);
    }
    // bfs(h);
    tree_t *t1,*t2,*root;
    for(i=0;i<n-1;i++)
    {
        t1 = delete_max(h);
        // bfs(h);
        t2 = delete_max(h);
        // bfs(h);
        // printf("t1: %d t2: %d total: %d\n",t1->freq,t2->freq,t1->freq+t2->freq);
        root = combt(t1,t2);
        insert2(h,root);
    } 
    int arr[2*n] ;
    dfs(h->data[1],arr,0);
}