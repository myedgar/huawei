#include <stdio.h>
#include <string.h>

#define M 100

char word_change(char word)
{
  char word_return;
  if(word >= 'a' && word <= 'c')
    word_return = '2';
  else if(word >= 'd' && word <= 'f')
    word_return = '3';
  else if(word >= 'g' && word <= 'i')
    word_return = '4';
  else if(word >= 'j' && word <= 'l')
    word_return = '5';
  else if(word >= 'm' && word <= 'o')
    word_return = '6';
  else if(word >= 'p' && word <= 's')
    word_return = '7';
  else if(word >= 't' && word <= 'v')
    word_return = '8';
  else if(word >= 'w' && word <= 'z')
    word_return = '9';
  else if(word >= 'A' && word <= 'Z'){
    if(word == 'Z'){
      word_return = 'a';
    } else {
      word_return = word-'A' + 'a' + 1;
    }
  }else {
    word_return = word;
  }
  return word_return;
}

void string_change(char *password)
{
  int i;
  int length = strlen(password);
  for(i = 0; i < length; i++){
    password[i] = word_change(password[i]);
  }
  printf("%s\n", password);
}

int main()
{
  char password[M];
  while(scanf("%s", password) != EOF){
    string_change(password);
  }
}
