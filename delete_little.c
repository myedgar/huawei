#include <stdio.h>
#include <string.h>

/*
/ 思路：设置一个数组，对字符进行统计，找出最小值
/       设置一个字符数组，保存删减后的字符串
/       对原有字符串进行对比，保存
*/
#define N 26
#define M 20        //字符串最大长度
int min_cal(int *a)
{
  int i;
  int min = M;    //最大可能全是一个字母，也就是20个
  for(i = 0; i < 26; i++)
    if(a[i] < min && a[i] > 0)    //为0就是不存在，不能考虑
      min = a[i];
  return min;
}

void count(char *str, int *a)
{
  int i;
  int length = strlen(str);
  for(i = 0; i < length; i++)
    a[str[i]-'a']++;
  return;
}

void after_delete(char *str, int *a,int min)
{
  int i;
  int j = 0;
  char answer[M];
  int length = strlen(str);
  for(i = 0; i < length; i++)
    if(a[str[i]-'a'] > min){
      answer[j] = str[i];
      j++;
    }
  answer[j] = '\0';
  printf("%s\n", answer);
}

int main()
{
  char str[M];
  while(scanf("%s", str) != EOF){
    int min;
    int a[N] = {0};
    count(str, a);
    min = min_cal(a);
    after_delete(str, a, min);
  }
}
