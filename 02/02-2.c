#include <stdio.h>

int main(void)
{
  int odd[10000], even[10000];
  int size_odd = 0, size_even = 0;
  int temp = -1;
  scanf("%d", &temp);
  int pos = 1;
  while (temp != 0)
  {
    if (pos % 2 == 0)
    {
      even[size_even] = temp;
      ++size_even;
    }
    else
    {
      odd[size_odd] = temp;
      ++size_odd;
    }
    scanf("%d", &temp);
    ++pos;
  }
  for(int i = 0; i < size_odd; ++i)
    printf("%d ", odd[i]);
  for(int i = size_even - 1; i >= 0; --i)
    printf("%d ", even[i]);
  return 0;
}
