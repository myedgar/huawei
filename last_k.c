#include <stdio.h>

#define M 1024

typedef struct
{
  int number[M];
  int n;
} heap;

void exchange(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
  return;
}

int parent(int i)
{
  return(i/2);
}

int left(int i)
{
  return(2*i);
}

int right(int i)
{
  return(2*i+1);
}
void max_heapify(heap *my_heap, int i)
{
  int largest;
  int l = left(i);
  int r = right(i);

  if(l < my_heap->n && my_heap->number[l] > my_heap->number[i])
  {
    largest = l;
  }
  else
    largest = i;
  if(r < my_heap->n && my_heap->number[r] > my_heap->number[largest])
  {
    largest = r;
  }
  if(largest != i)
  {
    exchange(&my_heap->number[i], &my_heap->number[largest]);
    max_heapify(my_heap, largest);
  }
}

void build_heap(heap *my_heap)
{
  int i;
  for(i = (my_heap->n-1)/2; i >= 0; i--)
  {
    max_heapify(my_heap, i);
  }
}

void heapsort(heap *my_heap, int k)
{
  int i;
  build_heap(my_heap);
  for(i = my_heap->n-1; i >= my_heap->n-k; i--)
  {
    exchange(my_heap->number[0],my_heap->number[i]);
    printf("%d ", my_heap->number[i]);
    my_heap->n = my_heap->n-1;
    max_heapify(my_heap, 0);
  }
}

int main()
{
  int k;
  heap my_heap;
  while(scanf("%d %d", &my_heap.n, &k) != EOF && k <= my_heap.n && k > 0 && my_heap.n > 0)
  {
    int i;
    for(i = 0; i < my_heap.n; i++)
    {
      scanf("%d", &my_heap.number[i]);
    }
    heapsort(&my_heap, k);
    printf("\n");
  }
}
