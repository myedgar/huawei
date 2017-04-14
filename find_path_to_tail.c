#include <stdio.h>
#include <stdlib.h>
typedef struct list_node
{
  int key;
  struct list_node *next;
} list;

int main()
{
  int n;
  list list_head;
  while(scanf("%d", &n) != EOF && n > 0)
  {
    int k;
    int i;
    list *p, *q, *p_list;
    p = &list_head;
    p_list = NULL;
    q = NULL;
    for(i = 1; i <= n; i++)
    {
      int number;
      scanf("%d", &number);
      p_list = (list*)malloc(sizeof(list));
      p_list->key = number;

      p->next = p_list;
      p = p->next;
    }
    p->next = NULL;
    if(scanf("%d", &k) == EOF || k <= 0 || k > n)
    {
      return(0);
    }
    p = &list_head;
    for(i = 1; i <= k; i++)
    {
      p = p->next;
    }
    q = &list_head;
    while(p != NULL)
    {
      p = p->next;
      q = q->next;
    }
    printf("%d\n", q->key);
  }
}
