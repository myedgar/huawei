#include <stdio.h>

int main()
{
  int a,b;
  while(scanf("%d", &a) != EOF && scanf("%d", &b) != EOF)
  {
    int i = 1;
    while(i%a != 0 || i%b != 0)
    {
      i++;
    }
    printf("%d\n", i);
  }
}
