#include <stdio.h>
#include <stdlib.h>

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

void top(stack_t *s)
{
  if (s != NULL)
  {
    printf("%d\n", s->data);
  }
  else
  {
    printf("Stack is empty.\n");
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

void empty(stack_t *s)
{
  if (s == NULL)
    printf("Stack is empty.\n");
  else
    printf("Stack is not empty.\n");
}

void size(stack_t *s)
{
  int nub = 0;
  while (s != NULL)
  {
    nub++;
    s = s->next;
  }
  printf("%d\n", nub);
}

int main(void)
{
  stack_t *s = NULL;
  int n, i, command, value;

  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &command);
    switch (command)
    {
    case 1:
      scanf("%d", &value);
      s = push(s, value);
      break;
    case 2:
      top(s);
      break;
    case 3:
      s = pop(s);
      break;
    case 4:
      empty(s);
      break;
    case 5:
      size(s);
      break;
    }
  }
  return 0;
}