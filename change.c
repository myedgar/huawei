#include <stdio.h>

int main()
{
  int n;
  int number[10] = {0};
  char string[1024];
  while(scanf("%d", &n) != EOF)
  {
    int single_number;
    int i = -1;
    while(n != 0)
    {
      single_number = n%10;
      if(number[single_number] == 0)
      {
        number[single_number] = 1;
        i++;
        string[i] = single_number + '0';
      }
      n /= 10;
    }
    string[++i] = '\0';
    printf("%s", string);
  }
}
