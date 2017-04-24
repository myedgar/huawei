/*
/ 思路：创建四个进行，一层一层调用
/
*/
#include <stdio.h>
#include <pthread.h>

void pthread4(void *arg)
{
  putchar('D');
  pthread_exit((void*)4);
}

void pthread3(void *arg)
{
  int err;
  pthread_t tid4;

  putchar('C');
  err = pthread_create(&tid4, NULL, pthread4, NULL);
  pthread_join(tid4, NULL);
  pthread_exit((void*)3);
}

void pthread2(void *arg)
{
  int err;
  pthread_t tid3;

  putchar('B');
  err = pthread_create(&tid3, NULL, pthread3, NULL);
  pthread_join(tid3, NULL);
  pthread_exit((void*)2);
}

void pthread1(void *arg)
{
  int err;
  pthread_t tid2;

  putchar('A');
  err = pthread_create(&tid2, NULL, pthread2, NULL);
  pthread_join(tid2, NULL);
  pthread_exit((void*)1);
}

int main()
{
  int n;
  int err;
  pthread_t tid1;

  while(scanf("%d", &n) != EOF){
    while(n--){
       err = pthread_create(&tid1, NULL, pthread1, NULL);
       pthread_join(tid1, NULL);
    }
    printf("\n");
  }  
}
