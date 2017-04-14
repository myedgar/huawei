#include <stdio.h>

double get_cube_root(double input)
{
  double y = input;
  double x;
  do
  {
    x = y;
    y = x - (x*x*x-input)/(3*x*x);
  }while(y-x > 0.1 || y-x < -0.1);
  return(y);
}

int main()
{
  double input;
  while(scanf("%lf", &input) != EOF)
  {
    if(input-0 < 0.01 && input-0 > -0.01)
    {
      printf("%0.1f\n", 0.0);
      continue;
    }
    printf("%0.1f\n", get_cube_root(input));
  }
}
