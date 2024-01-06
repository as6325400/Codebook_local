#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct
{
  int mode;
  int *heap;
  int size;
} priority_queue;

void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
bool cmp(priority_queue *pq, int par, int child)
{
  return (pq->mode == 1 ? pq->heap[par] <= pq->heap[child] : pq->heap[par] >= pq->heap[child]);
}
void par_to_child(priority_queue *pq, int par)
{
  int lc = (par * 2) + 1, rc = lc + 1, tar = par;
  if (lc < pq->size)
    tar = cmp(pq, tar, lc) ? tar : lc;
  if (rc < pq->size)
    tar = cmp(pq, tar, rc) ? tar : rc;
  if (par == tar)
    return;
  swap(pq->heap + par, pq->heap + tar);
  par_to_child(pq, tar);
}
int pop(priority_queue *pq)
{
  if (pq->size == 0)
    return -1;
  swap(pq->heap, pq->heap + --(pq->size));
  par_to_child(pq, 0);
  return pq->heap[pq->size];
}
void child_to_par_heapify(priority_queue *pq, int child)
{
  int par = (child - 1) / 2;
  if (child)
  {
    if (!cmp(pq, par, child))
    {
      swap(pq->heap + par, pq->heap + child);
      child_to_par_heapify(pq, par);
    }
  }
}
void push(priority_queue *pq, int val)
{
  pq->heap[pq->size] = val;
  child_to_par_heapify(pq, pq->size++);
}
int top(priority_queue *pq)
{
  return (pq->size == 0 ? -1 : pq->heap[0]);
}
int size(priority_queue *pq)
{
  return pq->size;
}
int main()
{
  priority_queue min_heap = {1, (int *)malloc(sizeof(int) * 1000005), 0},
                 max_heap = {2, (int *)malloc(sizeof(int) * 1000005), 0};
}