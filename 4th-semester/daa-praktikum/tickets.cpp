#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int n, s;
  long long k;
  cin >> n >> s;

  if(pow(2, n) >= pow(2, s)){
    k = pow(2, n);
    k  %= 5741;
    cout << k << endl;
  }else{
    cout << 0 << endl;
  }
}