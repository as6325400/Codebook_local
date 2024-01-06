#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
  return strcmp(*(const char **)a, *(const char **)b);
}

const char *arr[] = {"apple", "orange", "banana", "grape", "cherry"};

int n = sizeof(arr) / sizeof(arr[0]);

// apple banana cherry grape orange
qsort(arr, n, sizeof(const char *), compare);
