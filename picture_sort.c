#include <stdio.h>
#include <string.h>

#define M 1024


void change(char *a, char *b)
{
  char c;
  c = *a;
  *a = *b;
  *b = c;  
}

void sort(char *str)
{
  int i, j;
  int length = strlen(str);
  for(i = 1; i < length; i++)
    for(j = 0; j < length -i; j++)
      if(str[j] > str[j+1])
        change(&str[j], &str[j+1]);
  printf("%s\n", str);
}

int main()
{
  char str[M];
  while(scanf("%s", str) != EOF){
    sort(str);
  }
}
