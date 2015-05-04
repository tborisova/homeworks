#include <cstdio>
#include <iostream>
using namespace std;
/* Максимален брой върхове в графа */
#define MAXN 150
#define MAX_VALUE 10000
/* Брой върхове в графа */
const unsigned n = 5;
/* Матрица на теглата на графа */
const int A[MAXN][MAXN] = {
{ 0, 16, 10, 1, 0 },
{ 16, 0, 100, 0, 15 },
{ 10, 100, 0, 0, 20 },
{ 1, 0, 0, 0, 0 },
{ 0, 15, 20, 0, 0 },
};
char used[MAXN];
unsigned minCycle[MAXN], cycle[MAXN];
int curSum, minSum;

void printCycle(void)
{ unsigned i;
   printf("Минимален Хамилтонов цикъл: 1");
   for (i = 0; i < n - 1; i++) printf(" %u", minCycle[i] + 1);
   printf(" 1, дължина %d\n", minSum);
}

/* Намира минимален Хамилтонов цикъл */
void hamilton(unsigned i, unsigned level)
{ unsigned k;
    if ((1 == i) && (level > 0)) {
      if (level == n) {
        minSum = curSum;
        for (k = 0; k < n; k++) minCycle[k] = cycle[k];
      }
      return;
  }
  cout << i << " " << level << " " << curSum << endl;
  if (used[i]) return;
  used[i] = 1;
  for (k = 0; k < n; k++)
    if (A[i][k] && k != i) {
      cycle[level] = k;
      curSum += A[i][k];
      if (curSum < minSum) /* прекъсване на генерирането */
        hamilton(k, level + 1);
      curSum -= A[i][k];
    }
    used[i] = 0;
  }

int main(void) {
  unsigned k;
  for (k = 0; k < n; k++) used[k] = 0;
  minSum = MAX_VALUE;
  curSum = 0;
  cycle[1] = 1;
  hamilton(1, 0);
  printCycle();
  return 0;
}