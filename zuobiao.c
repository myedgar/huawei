#include <stdio.h>
#include <string.h>
#include <math.h>

typedef enum
{
  false,
  true
} bool;

typedef struct
{
  int up_down;
  int left_right;
} direction;

bool BOOL = false;

bool length_is(int first, int last);
bool first_char(char *str, int first);
bool number_is(char *str, int first, int last);
int  change_str_to_number(char *str, int first, int last);
void add_point(char *str, int first, int last, int number, direction *dire);

int main()
{
  char str[4096];
  while(scanf("%s", str) != EOF)
  {
    int i, j, first, last;
    direction dire;
    int number;                               // the number of each direction 
    int length = strlen(str);                 // the length of the string you input
    i = first = last = -1; 
    dire.up_down = dire.left_right = 0;  
    number = 0;               
    for(i = 0; i <= length; i++)
    {
      if(str[i] == ';')
      {
        first = last+1;
        last = i;
        if(length_is(first, last) == 0)
        {
          continue;
        }
        if(first_char(str, first) == 0)
        {
          continue;
        }
        if(number_is(str, first, last) == 0)
        {
          continue;
        }
        number = change_str_to_number(str,first, last);
        add_point(str, first, last, number, &dire);
      }
    }
    printf("%d,%d\n", dire.left_right, dire.up_down);
  }
}

bool length_is(int first, int last)
{
  if((last-first) <= 3)
    BOOL = true;
  else
    BOOL = false;
  return BOOL;
}
bool first_char(char *str, int first)
{
  if(str[first] == 'A' || str[first] == 'W' || str[first] == 'D'|| str[first] == 'S')
    BOOL = true;
  else
    BOOL = false;
  return BOOL;
}
bool number_is(char *str, int first, int last)
{
  int i;
  BOOL = true;
  for(i = first+1; i < last; i++)
  {
    if(str[i] < '0' || str[i] > '9')
    {
      BOOL = false; 
    }
  }
  return BOOL;
}
int  change_str_to_number(char *str, int first, int last)
{
  int i;
  int number = 0;
  for(i = first+1; i < last; i++)
  {
    number += (str[i] - '0')*pow(10,last-i-1);
  }
  return(number);
}
void add_point(char *str, int first, int last, int number, direction *dire)
{
  switch(str[first])
  {
    case 'A':
      dire->left_right -= number;
      break;
    case 'D':
      dire->left_right += number;
      break;
    case 'W':
      dire->up_down += number;
      break;
    case 'S':
      dire->up_down -= number;
      break;
  }
  return;
}
