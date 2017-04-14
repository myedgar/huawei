#include <stdio.h>
#include <string.h>

#define M 1024

int main()
{
  char str[M];
  while(gets(str) != NULL)
  {
    int count, i, length;
    length = strlen(str);
    count = 0;
    for(i = 0; i < length; i++)
    {
      if(str[i] >= 'A' && str[i] <= 'Z')
      {
        count++;
      }
    }
    printf("%d\n",count);
  }
}
