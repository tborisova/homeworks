#include <iostream>
using namespace std;
#define N 101
#define MOD 1000000007

int a[N][2];
int n, k;

void f()
{
	a[1][0] = k - 1;
	a[1][1] = 1;
	for (int i = 2; i <= n; i++)
	{
		long long s = a[i - 1][0] + a[i - 1][1];
		s *= k - 1;
		s %= MOD;
		a[i][0] = s;
		a[i][1] = a[i - 1][0];
	}
}

int main()
{
	cin >> n >> k;
	f();
	cout << (a[n][0] + a[n][1]) % MOD << endl;
}