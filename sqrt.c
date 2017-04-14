#include <stdio.h>
#include <math.h>
int main()
{
  unsigned long i = 0;
  while(1)
  {
    double b,c;
    b = sqrt(i+100);
    c = sqrt(i+268);
    if((int)b == b)
    {
      if((int)c == c)
      {
        printf("%d\n", i);
        break;
      }
    }
    i++;
  }
}
