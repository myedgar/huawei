#include <stdio.h>

#define M 60
#define N 3200

typedef struct{
  int v;
  int p;
  int q;
} goods;

int max(int a, int b)
{
  return a>b?a:b;
}
int dp(goods *my_goods, int n, int m)
{
  int demo[M][N];
  int i, j;
  int answer = 0;
  for(j = 0; j <= n/10; j++){
    demo[0][j] = 0;
  }
  for(i = 0; i <= m; i++){
    demo[i][0] = 0;
  }
  for(i = 1; i <= m; i++){
    for(j = 1; j <= n/10; j++){
      if(my_goods[i].q == 0 || my_goods[my_goods[i].q].q == 0){
        if(j < my_goods[i].v){
          demo[i][j] = demo[i-1][j];
        }else{
          demo[i][j] = max(demo[i-1][j],demo[i-1][j-my_goods[i].v]+my_goods[i].v*my_goods[i].p);
        }
      }
      if(demo[i][j] > answer){
        answer = demo[i][j];
      }
    }
  } 
  return answer;  
}

int main()
{
  int n, m;
  while(scanf("%d %d", &n, &m) != EOF)
  {
    int i;
    goods my_goods[M];
    for(i = 1; i <= m; i++)
    {
      scanf("%d %d %d", &my_goods[i].v, &my_goods[i].p, &my_goods[i].q);
    }
    printf("%d\n", dp(my_goods, n, m));
  }
}
