#include <stdio.h>
#include <stdlib.h>

int values[] = { 88, 56, 100, 2, 25 };

int cmpfunc (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

// 2 25 56 88 100 
qsort(values, 5, sizeof(int), cmpfunc);
