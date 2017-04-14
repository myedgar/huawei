#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define M 1024

typedef struct
{
  char str[M];
  int len;
} stack;

void push(stack *s, char c)
{
  s->str[++s->len] = c;
}

char pop(stack *s)
{
  if(s->len == -1)
  {
    exit(1);
  }
  s->len--;
  return(s->str[s->len+1]);
}

int main()
{
  char string[M];
  while(gets(string) != NULL)
  {
    stack s;
    s.len = -1;
    int i;
    int length = strlen(string);
    for(i = 0; i < length; i++)
    {
      push(&s, string[i]);
    }
    while(s.len != -1)
    {
      printf("%c", pop(&s));
    }
//    printf("\n");
  }
}
