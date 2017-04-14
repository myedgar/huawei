#include <stdio.h>
#include <string.h>

#define M 1024
int main()
{
  char string[M];
  while(scanf("%s", string) != EOF)
  {
    int ASCII[128] = {0};
    int i;
    int counter = 0;
    int length = strlen(string);
    for(i = 0; i < length; i++)
    {
      if(ASCII[string[i]] == 0)
      {
        counter++;
        ASCII[string[i]]++;
      }
    }
    printf("%d\n", counter);
  }
}
