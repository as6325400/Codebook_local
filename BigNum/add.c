#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char *a, char *b)
{
  char temp = *a;
  *a = *b;
  *b = temp;
}

char *add(char *s1, char *s2)
{
  char *ans = (char *)malloc(sizeof(char) * 200);
  int len1 = strlen(s1);
  int len2 = strlen(s2);
  for (int i = len1; i < 200; i++)
  {
    s1[i] = '0';
  }
  for (int i = len2; i < 200; i++)
  {
    s2[i] = '0';
  }
  for (int i = 0; i < len1 / 2; i++)
  {
    swap(&s1[i], &s1[len1 - i - 1]);
  }
  for (int i = 0; i < len2 / 2; i++)
  {
    swap(&s2[i], &s2[len2 - i - 1]);
  }

  int carry = 0, len3 = 0;
  for (int i = 0; i < 200; i++)
  {
    int num1 = s1[i] - '0';
    int num2 = s2[i] - '0';
    ans[i] = (char)(((num1 + num2 + carry) % 10) + (int)'0');
    if (ans[i] != '0')
      len3 = i + 1;
    carry = (num1 + num2 + carry) / 10;
  }
  for (int i = 0; i < len3 / 2; i++)
  {
    swap(&ans[i], &ans[len3 - i - 1]);
  }
  for (int i = len3; i < 200; i++)
  {
    ans[i] = '\0';
  }
  return ans;
}

int main()
{
  char *s1 = (char *)malloc(sizeof(char) * 200);
  char *s2 = (char *)malloc(sizeof(char) * 200);
  scanf("%s %s", s1, s2);
  printf("%s", add(s1, s2));
  return 0;
}