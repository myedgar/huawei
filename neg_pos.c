#include <stdio.h>

int main()
{
  int i = 0;
  int j = 0;
  int number;
  float sum = 0;
  while(scanf("%d", &number) != EOF)
  {
    if(number < 0)
    {
      i++;
    }
    else
    {
      sum += number;
      j++;
    }
  }
  printf("%d ", i);
  if(j == 0)
  {
    printf("0.0\n");
  }
  else
  {
    printf("%0.1f\n", sum/j);
  }
}
