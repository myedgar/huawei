#include <stdio.h>

double get_journey(int hight)
{
   float h = (float)hight;
   return(h+h+h/2+h/4+h/8);
}

double get_hight(int hight)
{
  float h = (float)hight;
  return(h/32);
}

int main()
{
  int hight;
  while(scanf("%d", &hight) != EOF)
  {
    printf("%f\n%f\n", get_journey(hight), get_hight(hight));
  }
}
