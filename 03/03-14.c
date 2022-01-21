#include <stdio.h>

int check (char prev[], char curr[], int player)
{
  if (player == 1)
  {
    if ((curr[0] - prev[0] == 2 || curr[0] - prev[0] == -2) && (curr[1] - prev[1] == 1 || curr[1] - prev[1] == -1))
      return 1;
    else if ((curr[0] - prev[0] == 1 || curr[0] - prev[0] == -1) && (curr[1] - prev[1] == 2 || curr[1] - prev[1] == -2))
      return 1;
    else return 0;
  }
  else
  {
    if ((curr[0] == prev[0] || curr[1] == prev[1]) && !(curr[0] == prev[0] && curr[1] == prev[1]))
      return 1;
    else if ((curr[0] - prev[0] == curr[1] - prev[1] || curr[0] - prev[0] == -(curr[1] - prev[1])) && !(curr[0] == prev[0] && curr[1] == prev[1]))
      return 1;
    else return 0;
  }
}

int main(void)
{
  char s[3];
  char prev[3];
  prev[0] = 'A', prev[1] = '1';
  int player = 0;
  int cheat = 0;
  int winner = -1;
  scanf("%s", s);
  while (s[0] != 'X')
  {
    if (player == 0)
      player = 1;
    else
      player = 0;
    int res = check(prev, s, player);
    if (res == 0)
      cheat = 1;
    if (winner != -1)
      cheat = 1;
    if (res == 1 && s[0] == 'H' && s[1] == '8' && winner == -1)
      winner = player;
    prev[0] = s[0], prev[1] = s[1];
    scanf("%s", s);
  }
  if (cheat)
    printf("Cheaters");
  else if (winner == -1)
    printf("Cheaters");
  else if (winner == 0)
    printf("Tolik");
  else
    printf("Garik");
  return 0;
}
