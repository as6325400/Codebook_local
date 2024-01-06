// 大數乘法
#include <stdio.h>
#include <math.h>
#include <string.h>
#define M 10005
char s1[M], s2[M], s[M];
int a[M], b[M], c[M];
int main()
{
  int i, j, m, n, k;
  while (~scanf("%s%s"

                ,
                s1, s2))
  {
    memset(c, 0, sizeof(c));
    n = strlen(s1);
    m = strlen(s2);
    k = n + m; // 保證相乘後的位數不會大於k
    printf("s1的長度=%d s2的長度=%d\n", n, m);
    /*把字串s1和s2逆序用數字排列*/
    for (i = 0; i < n; i++)
      a[i] = s1[n - i - 1] - '0';
    for (i = 0; i < m; i++)
      b[i] = s2[m - 1 - i] - '0';
    /* 乘運算*/

    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++)
        c[i + j] += a[i] * b[j];
    for (i = 0; i <= k; i++)
    {
      if (c[i] >= 10)
      {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
      }
    }
    /*去除前導0*/
    i = k;
    while (c[i] ==

           0)
      i--;
    /*判斷兩個非負數之積是否為0，以及逆序列印c[]*/
    if (i < 0)
      printf("0");
    else
    {
      for (; i >= 0; i--)
        printf("%d", c[i]);
    }
    printf("\n");
  }
  return 0;
}