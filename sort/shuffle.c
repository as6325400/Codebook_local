#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void shuffle(int arr[], int n)
{
  srand(time(NULL));

  for (int i = n - 1; i > 0; i--)
  {
    int j = rand() % (i + 1);
    swap(&arr[i], &arr[j]);
  }
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int n = sizeof(arr) / sizeof(arr[0]);
  shuffle(arr, n);
  return 0;
}
