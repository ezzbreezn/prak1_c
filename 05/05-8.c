#include <stdio.h>
#include <stdlib.h>

struct cell
{
  long long x;
  long long y;
};

struct queue
{
  long long first;
  long long last;
};

int empty(struct queue *q)
{
  return (q -> last < q -> first);
}

void insert(struct queue *q, struct cell *cells, struct cell c)
{
  q -> last++;
  cells[q -> last].x = c.x, cells[q -> last].y = c.y;
}

struct cell pop(struct queue *q, struct cell *cells)
{
  struct cell res;
  if (empty(q))
  {
    res.x = -1, res.y = -1;
    return res;
  }
  res.x = cells[q -> first].x, res.y = cells[q -> first].y;
  q -> first++;
  return res;
}

void print(struct queue *q, struct cell *cells)
{
  for (long long i = q -> first; i <= q -> last; ++i)
    printf("%lld %lld\n", cells[i].x, cells[i].y);
}

_Bool not_used(long long x, long long y, long long **used, long long n)
{
  return (x >= 0 && y >= 0 && x < n && y < n && !used[x][y]);
}

int main(void)
{
  long long n, x1, y1, x2, y2;
  scanf("%lld %lld %lld %lld %lld", &n, &x1, &y1, &x2, &y2);
  --x1, --y1, --x2, --y2;
  long long **used;
  long long **board;
  struct cell *cells;
  struct cell moves[8];
  struct queue *q;
  used = (long long **) malloc(sizeof(long long *) * n);
  for (long long i = 0; i < n; ++i)
  {
    used[i] = (long long *) malloc(sizeof(long long) * n);
    for (long long j = 0; j < n; ++j)
      used[i][j] = 0;
  }
  board = (long long **) malloc(sizeof(long long *) * n);
  for (long long i = 0; i < n; ++i)
  {
    board[i] = (long long *) malloc(sizeof(long long) * n);
    for (long long j = 0; j < n; ++j)
      board[i][j] = -1;
  }
  cells = (struct cell *) malloc(sizeof(struct cell) * n * n);
  q = (struct queue *) malloc(sizeof(struct queue));
  q -> first = 0, q -> last = -1;

  moves[0].x = 1, moves[0].y = 2;
  moves[1].x = -1, moves[1].y = 2;
  moves[2].x = 1, moves[2].y = -2;
  moves[3].x = -1, moves[3].y = -2;
  moves[4].x = 2, moves[4].y = 1;
  moves[5].x = -2, moves[5].y = 1;
  moves[6].x = 2, moves[6].y = -1;
  moves[7].x = -2, moves[7].y = -1;
  struct cell t = {x1, y1};
  insert(q, cells, t);
  used[x1][y1] = 1;
  board[x1][y1] = 0;
  while (!empty(q))
  {
    struct cell del = pop(q, cells);
    long long tx = del.x, ty = del.y;
    for (long long i = 0; i < 8; ++i)
    {
      long long dx = moves[i].x, dy = moves[i].y;
      if (not_used(tx + dx, ty + dy, used, n))
      {
        struct cell temp = {tx + dx, ty + dy};
        insert(q, cells, temp);
        used[tx + dx][ty + dy] = 1;
        board[tx + dx][ty + dy] = board[tx][ty] + 1;
      }
    }
  }
  printf("%lld", board[x2][y2]);
  for (long long i = 0; i < n; ++i)
    free(used[i]);
  free(used);
  for (long long j = 0; j < n; ++j)
    free(board[j]);
  free(board);
  free(cells);
  return 0;
}
