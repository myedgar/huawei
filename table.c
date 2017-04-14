#include <stdio.h>
#include <stdlib.h>

#define M 1024
#define false 0
#define true 1

typedef struct
{
  int index;
  int value;
} table;

typedef struct
{
  table tab[M];
  int INDEX;
} my_list;

void add(my_list *list, int index, int value);
void sort(my_list *list);
void print(my_list *list);

int main()
{
  int number;
  while(scanf("%d", &number) != EOF)
  {
    int i;
    int index, value;
    my_list list;
    list.INDEX = -1;
    for(i = 0; i < number; i++)
    {
      scanf("%d %d", &index, &value);
      add(&list, index, value);
    }
    sort(&list);
    print(&list);
  } 
}

void add(my_list *list, int index, int value)
{
  int i;
  if(list->INDEX == -1)
  {
     list->INDEX++;
     list->tab[list->INDEX].index = index;
     list->tab[list->INDEX].value = value;
     goto LABEL;
  }
  else
  {
    for(i = 0; i <= list->INDEX; i++)
    {
      if(list->tab[i].index == index)
      {
        list->tab[i].value += value;
        goto LABEL;
      }
    }
    list->INDEX++;
    list->tab[list->INDEX].index = index;
    list->tab[list->INDEX].value = value;
  }
  LABEL:return;
}
void sort(my_list *list)
{
  int i,j;
  table temp;
  for(i = 1; i <= list->INDEX-1; i++)
  {
    for(j = 0; j <= list->INDEX-i; j++)
    {
      if(list->tab[j].index > list->tab[j+1].index)
      {
        temp = list->tab[j];
        list->tab[j] = list->tab[j+1];
        list->tab[j+1] = temp;
      }
    }
  }
  return;
}
void print(my_list *list)
{
  int i;
  for(i = 0; i <= list->INDEX; i++)
  {
    printf("%d %d\n", list->tab[i].index, list->tab[i].value);
  }
  return;
}
