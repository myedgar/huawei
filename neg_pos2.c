#include <stdio.h>

int main()
{
  int n;
  while(scanf("%d", &n) != EOF && n > 0)
  {
    int i;
    int neg = 0;
    int pos = 0;
    float sum = 0;
    int number;
    for(i = 0; i < n; i++)
    {
      scanf("%d", &number);
      if(number < 0)
      {
        neg++;
      }
      else
      {
        sum += number;
        pos++;
      }
    }
    if(pos == 0)
    {
      printf("%d 0", neg); 
    }
    else
      printf("%d %0.1f\n", neg, sum/pos);
    
  }
}
