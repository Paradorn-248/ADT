#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node_t;

node_t *append(node_t *startNode)
{
    int x;
    scanf("%d", &x);
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->data = x;
    node->next = NULL;
    node_t *tmp = startNode;
    if (startNode == NULL)
    {
        startNode = node;
    }
    else
    {
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = node;
    }
    return startNode;
}

void show(node_t *startnode)
{
    while (startnode != NULL)
    {
        printf("%d ", startnode->data);
        startnode = startnode->next;
    }
    printf("\n");
}

void get(node_t *startNode)
{
    int a,i,res;
    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        startNode = startNode->next;
    }res = startNode->data;
    printf("%d\n",res);
}

node_t *reverse(node_t *startNode)
{
    node_t *next=NULL,*last=NULL,*l = startNode;
    while(l!= NULL)
    {
        next = l->next;
        l->next = last;
        last = l;
        l = next;
    }
    startNode = last;
    return startNode;
}

node_t *cut(node_t *startNode)
{
    int a,b,i;
    scanf("%d %d",&a,&b);
    node_t *l = startNode;
    for(i=0;i<a;i++)
    {
        l = l->next;
        // printf("%p\n",l);
    }
    startNode = l;
    for(i=a;i<b;i++)
    {
        l = l->next;
    }
    l->next = NULL;
    return startNode;
}

int main(void)
{
    node_t *startNode;
    int n, i;
    char command;
    startNode = NULL;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf(" %c", &command);
        switch (command)
        {
        case 'A':
            startNode = append(startNode);
            break;
        case 'G':
            get(startNode);
            break;
        case 'S':
            show(startNode);
            break;
        case 'R':
            startNode = reverse(startNode);
            break;
        case 'C':
            startNode = cut(startNode);
            break;
        default:
            break;
        }
    }
    return 0;
}

