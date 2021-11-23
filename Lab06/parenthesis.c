#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *next;
} node_t;

typedef node_t stack_t;

stack_t *push(stack_t *s, char dat)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->data = dat;
    node->next = s;
    s = node;
    return s;
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

char top(stack_t *s)
{
    if (s != NULL)
    {
        return s->data;
    }
    else
    {
        return '0';
    }
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

int main()
{
    int n, i;
    scanf("%d", &n);
    char par[n];
    stack_t *s1 = NULL;
    scanf(" %s", par);
    if (n % 2 != 0)
    {
        printf("0\n");
        return 0;
    }
    for (i = 0; i < n; i++)
    {
        if (par[i] == '(' || par[i] == '[' || par[i] == '{')
        {
            s1 = push(s1, par[i]);
        }
        else if ((top(s1) == '(' && par[i] == ')') || (top(s1) == '[' && par[i] == ']') || (top(s1) == '{' && par[i] == '}'))
        {
            s1 = pop(s1);
        }
    }
    if (size(s1) == 0)
        printf("1");
    else
        printf("0");
    return 0;
}