#include <stdio.h>
/* Максимален брой върхове в графа */
#define MAXN 10
/* Брой върхове в графа */
const unsigned n = 6;
/* Матрица на съседство на графа */
const char A[MAXN][MAXN] = {}

char used[MAXN], cycl;
/* модифициран Depth-First-Search */
void DFS(unsigned i, int parent){
  unsigned k;
  used[i] = 1;
  for (k = 0; k < n; k++) {
    if (cycl) return;
    if (A[i][k]) {
      if (used[k] && k != parent) {
        printf("Графът е цикличен! \n");
        cycl = 1;
        return;
      }
      else if (k != parent)
        DFS(k, i);
    }
  }
}

int main(void) {
  unsigned k, i;
  for (k = 0; k < n; k++) used[k] = 0;
  cycl = 0;
  for (i = 0; i < n; i++) {
    if (!used[i]) DFS(i, -1);
    if (cycl) break;
  }

  if (0 == cycl) printf(" Графът е дърво (не съдържа цикли)!\n");
  return 0;
}