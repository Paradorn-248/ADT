#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next_sibling;
    struct node *first_child;
} node_t;

typedef node_t tree_t;

typedef struct node_q
{
    int data;
    struct node_q *next;
} node_q;

typedef node_q queue_t;

typedef struct node_s
{
    int data;
    struct node_s *next;
} node_s;

typedef node_s stack_t;

stack_t *push(stack_t *s, int dat)
{
    node_s *node = (node_s *)malloc(sizeof(node_s));
    node->data = dat;
    node->next = s;
    s = node;
    return s;
}

int top(stack_t *s)
{
    if (s != NULL)
    {
        return s->data;
    }
    else
    {
        return 0;
    }
}

stack_t *pop(stack_t *s)
{
    if (s != NULL)
    {
        stack_t *tmp = s;
        s = s->next;
        free(tmp);
    }
    return s;
}

int size(stack_t *s)
{
    int nub = 0;
    while (s != NULL)
    {
        nub++;
        s = s->next;
    }
    return nub;
}

queue_t *enqueue(queue_t *q, int dat)
{
    node_q *node = (node_q *)malloc(sizeof(node_q));
    node->data = dat;
    node->next = NULL;
    if (q == NULL)
    {
        q = node;
    }
    else
    {
        node->next = q;
        q = node;
    }
    return q;
}

queue_t *dequeue(queue_t *q)
{
    queue_t *tmp = q;
    if (tmp == NULL)
        printf("Queue is empty.\n");
    else
    {
        if (tmp->next == NULL)
        {
            tmp = NULL;
            return tmp;
        }
        while (tmp->next->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = NULL;
    }
    return q;
}

int empty(queue_t *q)
{
    if (q == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int front(queue_t *q)
{
    queue_t *tmp = q;
    if (tmp == NULL)
        printf("Queue is empty.\n");
    else
    {
        if (tmp->next == NULL)
        {
            return tmp->data;
        }
        while (tmp->next->next != NULL)
        {
            tmp = tmp->next;
        }
        return tmp->next->data;
    }
}

void show(queue_t *q)
{
    int nub = 0;
    queue_t *tmp = q;
    while (tmp != NULL)
    {
        nub++;
        tmp = tmp->next;
    }
    if (nub == 0)
        printf("Queue is empty.");
    int rev[nub], i = 0;
    while (q != NULL)
    {
        rev[i] = q->data;
        q = q->next;
        i++;
    }
    for (i = nub - 1; i >= 0; i--)
    {
        printf("%d ", rev[i]);
    }
    printf("\n");
}

node_t *search_pos(tree_t *t, int v)
{
    node_t *pos;
    if (t == NULL)
        return t;
    if (t->value == v)
        return t;
    pos = search_pos(t->first_child, v);
    if (pos != NULL)
        return pos;
    else
        return search_pos(t->next_sibling, v);
}
//3
int search(tree_t *t, int v)
{
    if (search_pos(t, v) != NULL)
        return 1;
    else
        return 0;
}
//1
node_t *attach(tree_t *t, int p, int v)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->value = v;
    node->next_sibling = NULL;
    node->first_child = NULL;
    node_t *pos = search_pos(t, p);
    if (p == -1)
    {
        t = node;
        return t;
    }
    if (pos->first_child == NULL)
        pos->first_child = node;
    else
    {
        pos = pos->first_child;
        while (pos->next_sibling != NULL)
        {
            pos = pos->next_sibling;
        }
        pos->next_sibling = node;
    }
    return t;
}
//4
int degree(tree_t *t, int v)
{
    node_t *pos;
    int nub = 0;
    pos = search_pos(t, v);
    pos = pos->first_child;
    while (pos != NULL)
    {
        pos = pos->next_sibling;
        nub++;
    }
    return nub;
}
//5
int is_root(tree_t *t, int v)
{
    if (t->value == v)
        return 1;
    else
        return 0;
}
//6
int is_leaf(tree_t *t, int v)
{
    node_t *pos = search_pos(t, v);
    if (pos->first_child == NULL)
        return 1;
    else
        return 0;
}

// 9
int jue = 0;
stack_t *find_path(stack_t *s, tree_t *t, int b)
{
    if (t == NULL)
    {
        return NULL;
    }
    if (t->value == b)
    {
        s = push(s, t->value);
        jue = 1;
        return s;
    }
    s = find_path(s, t->first_child, b);
    if (jue)
    {
        s = push(s, t->value);
        return s;
    }
    else
        return find_path(s, t->next_sibling, b);
}

void print_path(tree_t *t, int a, int b)
{
    stack_t *s = NULL;
    node_t *p = search_pos(t, a);
    s = find_path(s, p, b);
    int i = 0, l = size(s);
    for (i = 0; i < l; i++)
    {
        printf("%d ", top(s));
        s = pop(s);
    }
    printf("\n");
    jue = 0;
}
//2
node_t *parent(tree_t *t,int v)
{
    stack_t *s = NULL;
    s = find_path(s,t,v);   
    // printf("%d\n",size(s)); 
    if(size(s)==1)
    {
        return NULL;
    }
    while(size(s)!=2)
    {
        s = pop(s);
    }
    node_t *pos = search_pos(t,top(s));
    jue = 0;
    return pos;
}
tree_t *detach(tree_t *t,int v)
{
    node_t *par = parent(t,v);
    node_t *pos = search_pos(t,v);
    if(par->first_child->value==v)
    {
        
        par->first_child = pos->next_sibling;
    }
    else
    {
        node_t *tmp;
        tmp = par->first_child;
        while(tmp->next_sibling->value!=v)
        {
            tmp = tmp->next_sibling;
        }
        tmp->next_sibling = pos->next_sibling;
    }
    return t;
}
//7
void siblings(tree_t *t, int v)
{
    stack_t *s = NULL;
    s = find_path(s,t,v);   
    if(size(s)==1)
    {
        jue = 0;
        printf("\n");
        return;
    }
    while(size(s)!=2)
    {
        s = pop(s);
    }
    node_t *pos = search_pos(t,top(s));
    pos = pos->first_child;
    while(pos!=NULL)
    {
        if(pos->value!=v)
        {
            printf("%d ",pos->value);
        }
        pos = pos->next_sibling;
    }
    printf("\n");
    jue = 0;
}
//10
int path_length(tree_t *t, int a, int b)
{
    stack_t *s = NULL;
    node_t *p = search_pos(t, a);
    s = find_path(s, p, b);
    jue = 0;
    return size(s);
}
//8
int depth(tree_t *t, int v)
{
    return path_length(t, t->value, v) - 1;
}
//12
void ancestor(tree_t *t, int v)
{
    stack_t *s = NULL;
    s = find_path(s, t, v);
    int i = 0, l = size(s);
    for (i = 0; i < l; i++)
    {
        printf("%d ", top(s));
        s = pop(s);
    }
    printf("\n");
    jue = 0;
}
//14
tree_t *dfs(node_t *t)
{
    if (t == NULL)
    {
        return NULL;
    }
    printf("%d ", t->value);
    dfs(t->first_child);
    dfs(t->next_sibling);
}

//13
void bfs(tree_t *t)
{
    queue_t *q = NULL;
    tree_t *p = t;
    q = enqueue(q, p->value);
    while (!empty(q))
    {
        // show(q);
        p = search_pos(t, front(q));
        printf("%d ", front(q));
        q = dequeue(q);
        if (p->first_child != NULL)
        {
            q = enqueue(q, p->first_child->value);
            p = p->first_child;
            while (p->next_sibling != NULL)
            {
                // printf("%d ", p->value);
                q = enqueue(q, p->next_sibling->value);
                p = p->next_sibling;
            }
            // printf("\n");
        }
    }
    printf("\n");
}
//12
void descendant(tree_t *t, int v)
{
    node_t *p = search_pos(t, v);
    bfs(p);
}
//15

tree_t *print_tree2(tree_t *t,tree_t *start)
{
    if (t == NULL)
    {
        return NULL;
    }
    int dep = depth(start,t->value),i=0;
    for(i=0;i<dep;i++)
    {
        printf("   ");
    }
    printf("%d ", t->value);
    printf("\n");
    node_t *pos = print_tree2(t->first_child,start);
    return print_tree2(t->next_sibling,start);
}

tree_t *print_tree(tree_t *t)
{
    print_tree2(t,t);
}

int main(void)
{
    tree_t *t = NULL;
    int n, i, command;
    int parent, child, node, start, end;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &command);
        switch (command)
        {
        case 1:
            scanf("%d %d", &parent, &child);
            t = attach(t, parent, child);
            break;
        case 2:
            scanf("%d", &node);
            t = detach(t, node);
            break;
        case 3:
            scanf("%d", &node);
            printf("%d\n", search(t, node));
            break;
        case 4:
            scanf("%d", &node);
            printf("%d\n", degree(t, node));
            break;
        case 5:
            scanf("%d", &node);
            printf("%d\n", is_root(t, node));
            break;
        case 6:
            scanf("%d", &node);
            printf("%d\n", is_leaf(t, node));
            break;
        case 7:
            scanf("%d", &node);
            siblings(t, node);
            break;
        case 8:
            scanf("%d", &node);
            printf("%d\n", depth(t, node));
            break;
        case 9:
            scanf("%d %d", &start, &end);
            print_path(t, start, end);
            break;
        case 10:
            scanf("%d %d", &start, &end);
            printf("%d\n", path_length(t, start, end));
            break;
        case 11:
            scanf("%d", &node);
            ancestor(t, node);
            break;
        case 12:
            scanf("%d", &node);
            descendant(t, node);
            break;
        case 13:
            bfs(t);
            break;
        case 14:
            dfs(t);
            break;
        case 15:
            print_tree(t);
            break;
        }
    }
    return 0;
}