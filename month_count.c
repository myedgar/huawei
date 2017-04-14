#include <stdio.h>

int get_total_count(int month_count)
{
  if(month_count == 1 || month_count == 2)
  {
    return(1);
  }
  else
  {
    return(get_total_count(month_count-2)+ get_total_count(month_count-1));
  }
}

int main()
{
  int month;
  while(scanf("%d", &month) != EOF)
  {
    printf("%d\n", get_total_count(month));
  }
}
