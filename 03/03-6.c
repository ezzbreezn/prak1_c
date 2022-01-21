#include <stdio.h>

int seq (int i)
{
  if (i <= 3)
    return i;
  else if (i > 3 && i % 2 != 0)
    return 2 * seq (i + 3);
  else
    return 3 + seq (i / 2);
}

int main(void)
{
  int i;
  scanf("%d", &i);
  printf("%d", seq(i));
  return 0;
}
