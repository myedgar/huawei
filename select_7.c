#include <stdio.h>

int contain_seven(int number)
{
  int i = 0;
  while(number)
  {
    if(number%10 == 7)
    {
      i =1;
      break;
    }
    number = number/10;
  }
  return i;
}

int main()
{
  int n;
  while(scanf("%d", &n) != EOF)
  {
    int i, count = 0;
    for(i = 1; i <= n; i++)
    {
      if(i%7 == 0)
      {
        count++;
        continue;
      }
      if(contain_seven(i) == 1)
      {
        count++;
        continue;
      }
    }
    printf("%d\n", count);
  }
}
