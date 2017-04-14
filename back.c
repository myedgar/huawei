#include <stdio.h>
#include <string.h>

#define M 1024

int main()
{
  char str[M];
  while(gets(str) != NULL)
  {
    char *p = NULL;
    while((p=strrchr(str, ' ')) != NULL)
    {
      printf("%s ", p+1);
      *p = '\0';
    }
    printf("%s\n",str);
  }
}
