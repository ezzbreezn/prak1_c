#include <stdio.h>

void output(int temp)
{
  if (temp != 0)
  {
    int ntemp;
    scanf("%d", &ntemp);
    output(ntemp);
    printf("%d ", temp);
  }
}

int main(void)
{
  int temp;
  scanf("%d", &temp);
  output(temp);
  return 0;
}
