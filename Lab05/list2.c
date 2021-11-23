#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    double decimal;
    char text[10];
    int type;
    struct node *next;
} node_t;

node_t *append(node_t *startNode)
{
    int typ, x;
    double y;
    char z[10];
    scanf(" %d", &typ);
    node_t *node = (node_t *)malloc(sizeof(node_t));
    if (typ == 0)
    {
        scanf(" %d", &x);
        node->number = x;
        node->decimal = 0;
        strcpy(node->text, "0");
        node->type = 0;
    }
    else if (typ == 1)
    {
        scanf(" %lf", &y);
        node->number = 0;
        node->decimal = y;
        strcpy(node->text, "0");
        node->type = 1;
    }
    else if (typ == 2)
    {
        scanf(" %s", z);
        node->number = 0;
        node->decimal = 0;
        strcpy(node->text, z);
        node->type = 2;
    }
    node->next = NULL;
    node_t *l = startNode;
    if (startNode == NULL)
    {
        startNode = node;
    }
    else
    {
        while (l->next != NULL)
        {
            l = l->next;
        }
        l->next = node;
    }
    return startNode;
}

void show(node_t *l)
{
    while (l != NULL)
    {
        if (l->type == 0)
            printf("%d ", l->number);
        else if (l->type == 1)
            printf("%lf ", l->decimal);
        else if (l->type == 2)
            printf("%s ", l->text);
        l = l->next;
    }
    printf("\n");
}

void get(node_t *l)
{
    int a, i;
    scanf("%d", &a);
    for (i = 0; i < a; i++)
    {
        l = l->next;
    }
    if (l->type == 0)
        printf("%d\n", l->number);
    else if (l->type == 1)
        printf("%f\n", l->decimal);
    else if (l->type == 2)
        printf("%s\n", l->text);
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

void show_reverse(node_t *startNode)
{
    startNode = reverse(startNode);
    show(startNode);
    startNode = reverse(startNode);
}

int length(node_t *l)
{
    int count = 0;
    while(l!=NULL)
    {
        count += 1;
        l = l->next;
    }
    return count;
}

void insert(node_t *l)
{
    int typ, x,pos,i;
    double y;
    char z[10];
    scanf(" %d %d",&pos, &typ);
    node_t *node = (node_t *)malloc(sizeof(node_t));
    for(i=0;i<pos;i++)
    {
        l = l->next;
    }
    node->next = l->next;
    if (typ == 0)
    {
        scanf(" %d", &x);
        node->number = x;
        node->decimal = 0;
        strcpy(node->text, "0");
        node->type = 0;
    }
    else if (typ == 1)
    {
        scanf(" %lf", &y);
        node->number = 0;
        node->decimal = 0;
        strcpy(node->text, "0");
        node->type = 1;
    }
    else if (typ == 2)
    {
        scanf(" %s", z);
        node->number = 0;
        node->decimal = 0;
        strcpy(node->text, z);
        node->type = 2;
    }
    l->next = node;
}

void is_empty(node_t *l)
{
    int a = length(l);
    if (a > 0)
        printf("Not Empty\n");
    else 
        printf("Empty\n");
}

node_t *delete(node_t *l)
{
    int a,i;
    scanf(" %d",&a);
    node_t *tmp = l;
    if (a==0)
    {
        l = l->next;
        return l;
    }
    for(i=0;i<a-1;i++)
    {
        l = l->next;
    }
    l->next = l->next->next;
    return tmp;
}

void change(node_t *l)
{
    int i,pos,typ,ch0;
    double ch1;
    char ch2[10];
    scanf(" %d %d",&pos,&typ);
    for(i=0;i<pos;i++) 
    {
        l = l->next;
    }
    if(typ == 0)
    {
        scanf(" %d",&ch0);
        l->type = typ;
        l->number = ch0;
    }
    else if(typ == 1)
    {
        scanf(" %lf",&ch1);
        l->type = typ;
        l->decimal = ch1;
    }
    else if(typ == 2)
    {
        scanf(" %s",ch2);
        l->type = typ;
        strcpy(l->text,ch2);
    }
}

int main()
{
    int n, i;
    char command;
    scanf("%d", &n);
    node_t *startNode;
    startNode = NULL;
    for (i = 0; i < n; i++)
    {
        scanf(" %c", &command);
        switch (command)
        {
        case 'A':
            startNode = append(startNode);
            break;
        case 'S':
            show(startNode);
            break;
        case 'G':
            get(startNode);
            break;
        case 'R':
            show_reverse(startNode);
            break;
        case 'I':
            insert(startNode);
            break;
        case 'D':
            startNode = delete(startNode);
            break;
        case 'C':
            change(startNode);
            break;
        case 'E':
            is_empty(startNode);
            break;
        case 'L':
            printf("%d\n",length(startNode));
            break;
        default:
            break;
        }
    }
    return 0;
}

