#include <stdio.h>
#include <string.h>

#define M 1024

typedef struct{
  char array[M];
  int top_of_stack;
} stack;

void push(stack *s, char x)
{
  s->top_of_stack++;
  s->array[s->top_of_stack] = x;
}

char pop(stack *s)
{
  if(s->top_of_stack == -1){
    return(-1); 
  }
  s->top_of_stack--;
  return(s->array[s->top_of_stack+1]);
}

void infix_postfix(char *infix_str, char postfix_str)
{
  
}
int postfix_answer(char *postfix_str)
{
  
}

int main()
{
  char infix_str[M];
  char postfix_str[M];
  while(scanf("%s", infix_postfix) != EOF){
    infix_postfix(infix_str, postfix_str);
    printf("%d\n", postfix_str(postfix_str));
  }
}
