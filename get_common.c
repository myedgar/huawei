#include <stdio.h>
#include <string.h>

#define M 1024
int get_common_str_length(char *str1, char *str2)
{
  int dp[M][M];
  int i,j;
  int max;
  int length1, length2;
  max = 0;
  length1 = strlen(str1);
  length2 = strlen(str2);
  for(i = 0; i < length1; i++)
  {
    for(j = 0; j < length2; j++)
    {
      if(str1[i] == str2[j])
      {
        if(i == 0 || j == 0)
        {
          dp[i][j] = 1;
        }
        else
        {
          dp[i][j] = dp[i-1][j-1] + 1;
        }
        if(dp[i][j] > max)
        {
          max = dp[i][j];
        }
      }
      else
      {
        dp[i][j] = 0;
      }
    }
  }
  return max;
}

int main()
{
  char str1[M], str2[M];
  while(scanf("%s %s", str1,str2) != EOF)
  {
    printf("%d\n", get_common_str_length(str1,str2));
  }
}
