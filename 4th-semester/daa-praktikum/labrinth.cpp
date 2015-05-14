#include <stdio.h>
/* Максимален брой върхове в графа */
#define MAXN 200
/* Брой върхове в графа */
const unsigned n = 14;
const unsigned sv = 1; /* Начален връх */
const unsigned ev = 10; /* Краен връх */
/* Матрица на съседство на графа */
const char A[MAXN][MAXN] = {
{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,0,0},
{0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,0,0},
{0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1,0,0},
{0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0,0,0},
{0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,0,0},
{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,1,1},
{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0,0,0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,0,0},
{0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0,0,0},
{0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,0,1},
{0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,1,0}
};

char used[MAXN];
unsigned path[MAXN], count;

void printPath(void)
{  
    unsigned k;
    for (k = 0; k <= count; k++)
      printf("%u ", path[k] + 1);
    printf("\n");
}

void allDFS(unsigned i, unsigned j)
{ unsigned k;
  if (i == j) {
    path[count] = j;
    printPath();
    return;
  }
  /* маркиране на посетения връх */
  used[i] = 1;
  path[count++] = i;
  for (k = 0; k < n; k++) /* рекурсия за всички съседи на i */
  if (A[i][k] && !used[k]) allDFS(k, j);
  /* връщане: размаркиране на посетения връх */
  used[i] = 0; count--;
}

int main(void) {
  unsigned k;
  for (k = 0; k < n; k++) used[k] = 0;
  count = 0;
  printf("Прости пътища между %u и %u: \n", sv, ev);
  allDFS(sv-1, ev-1);
return 0;
}