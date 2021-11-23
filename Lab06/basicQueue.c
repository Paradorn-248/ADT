#include <stdio.h>
#include <stdlib.h>

typedef struct node_q {
  int data;
  struct node_q *next;
} node_q;

typedef node_q queue_t;

queue_t *enqueue(queue_t *q,int dat)
{
  node_q *node = (node_q *)malloc(sizeof(node_q));
  node->data = dat;
  node->next = NULL;
  if(q==NULL)
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
  if(tmp==NULL)
    printf("Queue is empty.\n");
  else
  {
    if(tmp->next==NULL)
    {
      printf("%d\n",tmp->data);
      tmp = NULL;
      return tmp;
    }
    while(tmp->next->next!=NULL)
    {
      tmp = tmp->next;
    }
    printf("%d\n",tmp->next->data);
    tmp->next = NULL;
  }
  return q;
}

void show(queue_t *q)
{
  int nub = 0;
  queue_t *tmp = q;
  while(tmp!=NULL)
  {
    nub++;
    tmp = tmp->next;
  }
  if(nub==0)
    printf("Queue is empty.");
  int rev[nub],i=0;
  while(q!=NULL)
  {
    rev[i] = q->data;
    q = q->next;
    i++;
  }
  for(i=nub-1;i>=0;i--)
  {
    printf("%d ",rev[i]);
  }
  printf("\n");
}

void empty(queue_t *q)
{
  if(q==NULL)
  {
    printf("Queue is empty.\n");
  }
  else
  {
    printf("Queue is not empty.\n");
  }
}

void size(queue_t *q)
{
  int nub = 0;
  while(q!=NULL)
  {
    nub++;
    q = q->next;
  }
  printf("%d\n",nub);
}

int main(void) {
  queue_t *q = NULL;
  int n, i, command, value;

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch(command) {
      case 1:
        scanf("%d", &value);
        q = enqueue(q, value);
        break;
      case 2:
        q = dequeue(q);
        break;
      case 3:
        show(q);
        break;
      case 4:
        empty(q);
        break;
      case 5:
        size(q);
        break;
    }
  }
  return 0;
}