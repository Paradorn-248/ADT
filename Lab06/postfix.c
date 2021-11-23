#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    float data;
    struct node *next;
} node_t;

typedef node_t stack_t;

stack_t *push(stack_t *s, float dat)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->data = dat;
    node->next = s;
    s = node;
    return s;
}

float top(stack_t *s)
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

int main()
{
    stack_t *s = NULL;
    int n, i;
    float tmp;
    scanf("%d", &n);
    char eq[n + 1];
    scanf(" %s", eq);
    for (i = 0; i < n; i++)
    {
        if (eq[i] != '+' && eq[i] != '-' && eq[i] != '*' && eq[i] != '/')
        {
            s = push(s, eq[i] - 48);
            // printf("%c num:%.2f\n",eq[i],top(s));
        }
        else
        {
            if (eq[i] == '+')
            {
                tmp = top(s);
                s = pop(s);
                tmp = tmp + top(s);
                s = pop(s);
                s = push(s, tmp);
            }
            if (eq[i] == '-')
            {
                tmp = top(s);
                s = pop(s);
                tmp = top(s) - tmp;
                s = pop(s);
                s = push(s, tmp);
            }
            if (eq[i] == '*')
            {
                tmp = top(s);
                s = pop(s);
                tmp *= top(s);
                s = pop(s);
                s = push(s, tmp);
            }
            if (eq[i] == '/')
            {
                tmp = top(s);
                s = pop(s);
                tmp = top(s) / tmp;
                s = pop(s);
                s = push(s, tmp);
            }
        }
    }
    printf("%.2f", top(s));
    return 0;
}