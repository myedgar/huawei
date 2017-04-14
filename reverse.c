#include <stdio.h>

#define M 1024

int main()
{
  int n;
  while(scanf("%d", &n) != EOF)
  {
    char str[M];
    int i =-1;
    if(n != 0)
    {
      while(n != 0)
      {
        str[++i] = n%10 + '0';
        n /= 10;
      }
      str[++i] = '\0';
    }
    else
    {
      str[0] = '0';
      str[1] = '\0';
    }
    printf("%s\n", str);
  }
    
}
