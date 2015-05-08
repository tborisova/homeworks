#include <iostream>
#include<cstdio>
#include<climits>
#include<algorithm>
using namespace std;

#define N 512
// Infinity: INF + INF must not overflow
#define INF INT_MAX / 2

int a[N][N];
int n, m, q;

void floyd()
{
	for (int k = 0; k<n; k++)
	for (int i = 0; i<n; i++)
	for (int j = 0; j<n; j++)
		a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
}

int main()
{
	int u, v, w;

	scanf("%d%d", &n, &m);
	// initialization before floyd
	for (int i = 0; i<n; i++)
	for (int j = 0; j<n; j++)
		a[i][j] = INF;
	for (int i = 0; i<n; i++)
		a[i][i] = 0;

	//input
	for (int i = 0; i<m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		a[u][v] = min(a[u][v], w); // ako a[u][v] e 2, a nie chetem 5, togava sthe презапишем 2 и после няма да получим резултата.
	}

	floyd();

	// queries
	scanf("%d", &q);
	for (int i = 0; i<q; i++)
	{
		scanf("%d%d", &u, &v);
		w = a[u][v];
		if (w == INF)
			printf("unreachable\n");
		else
			printf("%d\n", w);
	}

	return 0;
}