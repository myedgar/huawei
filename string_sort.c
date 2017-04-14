#include <stdio.h>
#include <string.h>
#define M 1024
typedef struct
{
  char str[M];
} directory;


void exchange(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
  return;
}

int main()
{
  directory dire[M];
  int n;
  while(scanf("%d", &n) != EOF)
  {
    int i, j;
    int a[M];
    for(i = 0; i < n; i++)
    {
      scanf("%s", dire[i].str);
      a[i] = i;
    }
    for(i = 1; i < n-1; i++)
    {
      for(j = 0; j < n-i; j++)
      {
        if(strcmp(dire[j].str,dire[j+1].str) > 0)
        {
          exchange(&a[j], &a[j+1]);
        }
      }
    }
    for(i = 0; i < n; i++)
    {
      printf("%s\n", dire[a[i]].str);
    }
  }
}
