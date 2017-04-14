#include <stdio.h>
#include <string.h>

#define M 1024

typedef enum bool{
  NG,
  OK
} pass;

pass check_length(char *str)
{
  return strlen(str) > 8 ? OK : NG;
}

pass check_type(char *str)
{
  int i;
  int capital = 0;
  int lowercase = 0;
  int number = 0;
  int other_symble = 0;
  int length = strlen(str);
  for(i = 0; i < length; i++){
    if(str[i] >= 'A' && str[i] <= 'Z'){
      capital = 1;
    }else if(str[i] >= 'a' && str[i] <= 'z'){
      lowercase = 1;
    }else if(str[i] >= '0' && str[i] <= '9'){
      number = 1;
    }else{
      other_symble = 1; 
    }
  }
  return (capital + lowercase + number + other_symble) >=3 ? OK : NG;
}


pass single_check_str(char *str)
{
  int i, k;
  int next[M];
  int length = strlen(str);
  next[0] = 0;
  k = 0;
  for(i = 1; i < length; i++){
    while(k > 0 && str[k] != str[i]){
      k = next[k];
    }
    if(str[k] == str[i])
      k = k + 1;
    next[i] = k;
  }
  k = 0;
  for(i = 0; i < length; i++)
  {
    if(k < next[i]){
      k = next[i];
      if(k > 2)
        return(NG);
    }
  }
  return(OK);
}


pass check_str(char *str)
{
  int i;
  int length = strlen(str);
  for(i = 0; i < length; i++)
    if(single_check_str(str+i) == NG){
      return(NG);
    }
  return(OK);
      
}
int main()
{
  char str[M];
  pass check = OK;
  while(gets(str) != NULL)
  {
    if(check_length(str) == NG || check_type(str) == NG|| check_str(str) == NG){
      printf("NG\n");
    }else{
      printf("OK\n");
    }
  }
}
