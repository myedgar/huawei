#include <stdio.h>
#include <string.h>

static int get_English_char_count(char *str)
{
  int i;
  int count = 0;
  int length = strlen(str);
  for(i = 0; i < length; i++)
  {
    if(str[i] >= 'a' && str[i] <= 'z')
    {
      count++;
    }
    if(str[i] >= 'A' && str[i] <= 'Z')
    {
      count++;
    }
  } 
  return count;
}

static int get_blank_char_count(char *str)
{
  int i;
  int count = 0;
  int length = strlen(str);
  for(i = 0; i < length; i++)
  {
    if(str[i] == ' ')
      count++;
  }
  return count;
}
 
static int get_number_char_count(char *str)
{
  int i;
  int count = 0;
  int length = strlen(str);
  for(i = 0; i < length; i++)
  {
    if(str[i] >= '0' && str[i] <= '9') 
      count++;
  }
  return count;
}

int main()
{
  char str[1024];
  while(gets(str) != NULL)
  {
    int length = strlen(str);
    printf("%d\n", get_English_char_count(str));
    printf("%d\n", get_blank_char_count(str));
    printf("%d\n", get_number_char_count(str));
    printf("%d\n", length-get_English_char_count(str)- \
    get_blank_char_count(str)-get_number_char_count(str));
  }
}
