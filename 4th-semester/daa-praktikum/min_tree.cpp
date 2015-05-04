#include <cstdio>
#include <iostream>
using namespace std;
/* Максимален брой върхове
 в графа */
#define MAXN 150
/* Брой върхове в графа */
const unsigned n = 5;
/* Графът, представен с матрица на съседство: 0 - няма ребро; 1 – има;
* По-късно с 2 ще маркираме ребрата на покриващото дърво на графа.
*/
char A[MAXN][MAXN] = {
{ 0, 1, 1, 1, 0 },
{ 1, 0, 1, 0, 1 },
{ 1, 1, 0, 0, 1 },
{ 1, 0, 0, 0, 0 },
{ 0, 1, 1, 0, 0 },
};
char used[MAXN];
unsigned cycle[MAXN], d;
/* Намира произволно покриващо дърво */
void DFS(unsigned v)
{ unsigned i;
  used[v] = 1;
  for (i = 0; i < n; i++)
    if (!used[i] && A[v][i]) {
      A[v][i] = 2;
      A[i][v] = 2;
      DFS(i);
    }
}

/* Отпечатва намерен цикъл */
void printCycle(void)
{ unsigned k;
  cout << "d is" << d << endl;
   for (k = 0; k < d; k++)
     printf("%u ", cycle[k] + 1);
   printf("\n");
}
/* Намиране на един цикъл спрямо намереното покриващо дърво */
void DFS2(unsigned v, unsigned u)
{ unsigned i;
   if (v == u) { printCycle(); return; }
   used[v] = 1;
  for (i = 0; i < n; i++)
    if (!used[i] && 2==A[v][i]) {
      cycle[d++] = i;
      DFS2(i, u);
      d--;
    }
}

int main(void) {
 unsigned i, j, k; 
 DFS(0);
 for (i = 0; i < n; i++){
    if(A[i][j] == 2){
      cout << i << endl;
    }
 }
 printf("Простите цикли в графа са: \n");
 for (i = 0; i < n - 1; i++)
  for (j = i + 1; j < n; j++)
   if (1 == A[i][j]) {
      for (k = 0; k < n; k++) used[k] = 0;
      d = 1;
      cycle[0] = i;
      DFS2(i, j);
  }
return 0;
}