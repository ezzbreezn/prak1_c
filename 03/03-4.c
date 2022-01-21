#include <stdio.h>

void output (int x, int i)
{
  if (x != 0)
  {
    if (i % 2 != 0)
    {
      printf("%d ", x);
      int temp;
      scanf("%d", &temp);
      output(temp, i + 1);
    }
    else
    {
      int temp;
      scanf("%d", &temp);
      output(temp, i + 1);
      printf("%d ", x);
    }
  }
}


int main(void)
{
  int temp;
  scanf("%d", &temp);
  output(temp, 1);
  return 0;
}
