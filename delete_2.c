#include <stdio.h>

#define M 1000

int main()
{
  int n;
  while(scanf("%d", &n) != EOF)
  {
    int a[M] = {0};
    int count = 0;
    int i = 0;
    int k = 1;
    int flag = 0;
    do
    {
      i = i%n;
      if(a[i] == 0)
      {
        if(count == 2)
        {
          if(k == n)
          {
            flag = 1;
            printf("%d\n", i);
          }
          else
          {
            a[i] = 1;
            count = 0;
            k++;
          }
        }
        else
        {
          count++;
        }
      }
      i++;
    }while(flag == 0);
  }
}
