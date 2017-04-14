#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 1024
#define N 1024

typedef struct
{
  char string[N][LEN];
  int n;
} my_stack;

void push(my_stack *stack, char *str, int first, int last)
{
  int i;
  stack->n++;
  for(i = 0; i < last-first; i++)
  {
    stack->string[stack->n][i] = str[i+first];
  }
  stack->string[stack->n][i] = '\0';
  return;
}

void pop(my_stack *stack)
{
  int i;
  if(stack->n == -1)
  {
    exit(1);
  }
  printf("%s ", stack->string[stack->n--]);
  return;
}
int main()
{
  char str[LEN];
  while(gets(str) != NULL)
  {
    int i = 0;
    int first, last;
    int length = strlen(str);
    my_stack s;
    first = last = -1;
    s.n = -1;
    for(i = 0; i <= length; i++)
    {
      if(str[i] == ' ' || str[i] == '\0')
      {
        first = last+1;
        last = i;
        push(&s, str, first, last);
      }
    }
    while(1)
    {
      if(s.n == -1)
        break;
      pop(&s);
    }
    printf("\n");
  }
}
