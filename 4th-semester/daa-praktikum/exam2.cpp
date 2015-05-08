#include <cmath>
#include <iostream>
#include <cstdio>
using namespace std;

int main(){
  double a,b;

  cin >> a >> b;

  cout << fixed << noshowpoint << ceil((a-1)/(b+1)) << endl;
}
