#include <stdio.h>
#include <string.h>

#define M 1024

int min(int delete, int insert, int replace)
{
  int min;
  min = delete < insert ? delete : insert;
  min = min < replace ? min : replace;
  return min;
}

int edit_distance(char *str1, char *str2)
{
  int d[M][M];
  int i, j;
  int length1;
  int length2;
  length1 = strlen(str1);
  length2 = strlen(str2);
  for(i = 0; i <= length1; i++){
    d[i][0] = i;
  }
  for(j = 0; j <= length2; j++){
    d[0][j] = j;
  }
  for(i = 1; i <= length1; i++){
    for(j = 1; j <= length2; j++){
      if(str1[i-1] == str2[j-1]){
        d[i][j] = d[i-1][j-1];
      }else{
        d[i][j] = min(d[i-1][j]+1, d[i][j-1]+1, d[i-1][j-1]+1);
      }
    }
  }
  return(d[length1][length2]);
}

int main()
{
  char str1[M];
  char str2[M];
  while(scanf("%s", str1) != EOF && scanf("%s", str2) != EOF)
  {
    printf("1/%d\n", edit_distance(str1,str2)+1);
  }
}
