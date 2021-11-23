#include <stdio.h>
#include <stdlib.h>
#include "week8.h"
#include <math.h>

#ifndef __bin_tree__
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node_t;

typedef node_t tree_t;
#endif
//1
int is_full(tree_t *t)
{
    if(t->left==NULL&&t->right==NULL)
    {
        return 1;
    }
    else if((t->left!=NULL&&t->right==NULL)||(t->left==NULL&&t->right!=NULL))
    {
        return 0;
    }    
    int a = is_full(t->left);
    int b = is_full(t->right);    
    if(!a||!b)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
// int is_full2(tree_t *t)
// {
//     if((t->left==NULL&&t->right==NULL))
//     {
//         return 1;
//     }
//     else if((t->left!=NULL&&t->right==NULL)||(t->left==NULL&&t->right!=NULL))
//     {
//         return 0;
//     }    
//     is_full2(t->left);
//     is_full2(t->right);    
// }
//2
int size(tree_t *t)
{
    if (t==NULL)
    {
        return 0;
    }
    return size(t->left)+size(t->right)+1;
}
int height(tree_t *t)
{
    if(t==NULL)
    {
        return -1;
    }
    int hl = height(t->left);
    int hr = height(t->right);
    if(hl>hr)
    {
        return hl+1;
    }
    else
    {
        return hr+1;
    }
}
int is_perfect(tree_t *t)
{
    if(pow(2,height(t)+1)-1==size(t))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//3
// int is_complete(tree_t *t)
// {
//     if(t==NULL)
//     {
//         return 1;
//     }
//     if(t->left==NULL&&t->right==NULL)
//     {
//         return 1;
//     }
//     if(t->left==NULL&&t->right!=NULL)
//     {
//         return 0;
//     }
//     if(t->left!=NULL)
//     {
//         int a = is_complete(t->left),b=is_complete(t->right);
//         return a&&b;
//     }
//     else
//     {
//         return 0;
//     }
// }
int is_complete2(tree_t *t, int index, int s) 
{
    if (t == NULL)        
    {
        return 1;
    }
    if (index > s)        
    {
        return 0;
    }
    return (is_complete2(t->left, 2*index, s) && is_complete2(t->right, 2*index+1, s)); 
}//checkจากindexถ้ามองเป็นแบบarray ถ้าindexของลูกมัน(ซ้าย2*n ขวา2*n+1)เกินsizeของต้นไม้ ก็จะถือว่าไม่เป็น

int is_complete(tree_t *t)
{
    return is_complete2(t,1,size(t)); //start@index1
}
//4
int is_degenerate(tree_t *t)
{
    if(t==NULL)
    {
        return 1;
    }
    if(t->left==NULL&&t->right==NULL)
    {
        return 1;
    }
    else if(t->left!=NULL&&t->right!=NULL)
    {
        return 0;
    }
    int a = is_degenerate(t->left);
    int b = is_degenerate(t->right);    
    if(!a||!b)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int is_degenerate2(tree_t *t) //ทำแบบdfs
{
    //dfs
    if(t==NULL)
    {
        return 1;
    }
    if(t->left==NULL&&t->right==NULL)
    {
        return 1;
    }
    else if(t->left!=NULL&&t->right!=NULL)
    {
        return 0;
    }
    int a = is_degenerate2(t->left);
    int b = is_degenerate2(t->right);
    if(a&&b)
        return 1;
    else 
        return 0;
}
//5
int l = 0;
int is_skewed(tree_t *t)
{
    if(t==NULL)
    {
        return 1;
    }
    if(t->left!=NULL&&t->right!=NULL)
    {
        return 0;
    }
    if(t->left!=NULL&&t->right==NULL) //left
    {
        l = 1;
    }
    if(l)
    {
        if(t->right!=NULL)
            return 0;
        else
            return is_skewed(t->left);
    }
    else 
    {
        if(t->left!=NULL)
            return 0;
        else 
            return is_skewed(t->right);
    }
}

int main(void)
{
    tree_t *t = NULL;
    int n, i;
    int parent, child;
    int branch; // 0 root, 1 left, 2 right

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d", &parent, &child, &branch);
        t = attach(t, parent, child, branch);
    }

    // printf("%d %d %d %d %d\n", is_full(t), is_perfect(t), is_complete(t), is_degenerate(t), is_skewed(t));
    printf("%d %d %d %d %d %d\n",is_full(t),is_perfect(t),is_complete(t),is_degenerate(t),is_degenerate2(t),is_skewed(t));

    return 0;
}