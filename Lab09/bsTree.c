#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node_t;

typedef node_t bst_t;

int find(bst_t *t,int d)
{
    if (t==NULL)
        return 0;
    if(t->data==d)
        return 1;
    if(d<t->data)
        return find(t->left,d);
    if(d>t->data)
        return find(t->right,d);
}

bst_t *insert(bst_t *t,int d) 
{
    if (t==NULL)
    {
        node_t *node = (node_t *)malloc(sizeof(node_t));
        node->data = d;
        node->left = NULL;
        node->right = NULL;
        t = node;
        return t;
    }
    if(d<t->data)
    {   
        t->left = insert(t->left,d);
    }
    if(d>t->data)
    {
        t->right = insert(t->right,d);
    }
    return t;
}

int find_min(bst_t *t)
{
    while(t->left!=NULL)
    {
        t = t->left;
    }
    return t->data;
}

bst_t *delete(bst_t *t,int d)
{
    if (t==NULL)
        return t;
    if(t->data == d)
    {
        // case1
        if(t->left == NULL && t->right == NULL)
        {
            free(t);
            return NULL;
        }
        // case2
        if(t->left!=NULL &&t->right==NULL)
        {
            bst_t *tmp = t->left;
            free(t);
            return tmp;
        }
        if(t->left==NULL &&t->right!=NULL)
        {
            bst_t *tmp = t->right;
            free(t);
            return tmp;
        }
        // case3
        if(t->left != NULL && t->right != NULL)
        {   
            int a = find_min(t->right);
            t->data = a;
            t->right = delete(t->right,a);
        }
    }
    if(d<t->data)
        t->left = delete(t->left,d);
    else
        t->right = delete(t->right,d);
    return t;
}


int find_max(bst_t *t)
{
    while(t->right!=NULL)
    {
        t = t->right;
    }
    return t->data;
}

int main(void)
{
    bst_t *t = NULL;
    int n, i;
    int command, data;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &command);
        switch (command)
        {
        case 1:
            scanf("%d", &data);
            t = insert(t, data);
            break;
        case 2:
            scanf("%d", &data);
            t = delete (t, data);
            break;
        case 3:
            scanf("%d", &data);
            printf("%d\n", find(t, data));
            break;
        case 4:
            printf("%d\n", find_min(t));
            break;
        case 5:
            printf("%d\n", find_max(t));
            break;
        }
    }
    return 0;
}