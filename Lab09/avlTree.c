#include <stdio.h>
#include <stdlib.h>
#include <week9.h>

#ifndef __avl_tree__
typedef struct node
{
    int data;
    int height;
    struct node *left;
    struct node *right;
} node_t;

typedef node_t avl_t;
#endif

int height(avl_t *t)
{
    if(t==NULL)
        return -1;
    return t->height;
}

int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int chk(avl_t *t)
{
    if (t==NULL)
        return 0;
    if(height(t->left)-height(t->right)>1||height(t->left)-height(t->right)<-1)
        return 1;
    else 
        return 0;
}

avl_t *right_rotate(avl_t *t)
{
    avl_t *p = t;
    avl_t *l = t->left;
    p->left = l->right;
    l->right = p;
    p->height = max(height(p->left),height(p->right))+1;
    l->height = max(height(l->left),height(l->right))+1;
    return l;
}

avl_t *left_rotate(avl_t *t)
{
    avl_t *a = t;
    avl_t *b = t->right;
    a->right = b->left;
    b->left = a;
    a->height = max(height(a->left),height(a->right))+1;
    b->height = max(height(b->left),height(b->right))+1;
    return b;
}

avl_t *insert(avl_t *t,int d)
{
    if (t==NULL)
    {
        node_t *node = (node_t *)malloc(sizeof(node_t));
        node->data = d;
        node->height = 0;
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
    t->height = max(height(t->left),height(t->right))+1;
    if(chk(t))
    {
        //case1
        if(d<t->data&&d<t->left->data)
        {
            return right_rotate(t);
        }
        // case2
        if(d>t->data&&d>t->right->data)
        {
            return left_rotate(t);
        }
        // case3
        if(d<t->data&&d>t->left->data)
        {
            t->left = left_rotate(t->left);
            return right_rotate(t);
        }
        // case4
        if(d>t->data&&d<t->right->data)
        {
            t->right = right_rotate(t->right);
            return left_rotate(t);
        }
    }
    return t;
}

int find_min(avl_t *t)
{
    while(t->left!=NULL)
    {
        t = t->left;
    }
    return t->data;
}

avl_t *delete(avl_t *t,int d)
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
            avl_t *tmp = t->left;
            free(t);
            return tmp;
        }
        if(t->left==NULL &&t->right!=NULL)
        {
            avl_t *tmp = t->right;
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
    
    t->height = max(height(t->left),height(t->right))+1;
    if(chk(t))
    {
        //case1
        if(height(t->left)>height(t->right)&&height(t->left->left)>height(t->left->right))
        {
            return right_rotate(t);
        }
        // case2
        if(height(t->left)<height(t->right)&&height(t->right->left)<height(t->right->right))
        {
            return left_rotate(t);
        }
        // case3
        if(height(t->left)>height(t->right)&&height(t->left->left)<height(t->left->right))
        {
            t->left = left_rotate(t->left);
            return right_rotate(t);
        }
        // case4
        if(height(t->left)<height(t->right)&&height(t->right->left)>height(t->right->right))
        {
            t->right = right_rotate(t->right);
            return left_rotate(t);
        }
    }
    return t;
}

int main(void)
{
    avl_t *t = NULL;
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
            print_tree(t);
            break;
        }
    }
    return 0;
}