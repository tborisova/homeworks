#include <iostream>
#include <algorithm>
using namespace std;
#define N 1000000

int a[N];
int n;

int f()
{
	int maxSum = 0;
	int maxEndingAtI = 0;
	for (int i = 0; i < n; i++)
	{
		maxEndingAtI += a[i];
		maxEndingAtI = max(maxEndingAtI, 0);
		maxSum = max(maxSum, maxEndingAtI);
	}
	return maxSum;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << f() << endl;
}