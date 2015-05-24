#include <iostream>
using namespace std;

#define MAXN[91]
int n;

int main(){

  neighbours["e"].push_back("0");
  neighbours["e"].push_back("1");

  neighbours["0"].push_back("00");
  neighbours["0"].push_back("01");

  neighbours["1"].push_back("10");
  neighbours["1"].push_back("11");

  while(cin >> n){
    int limit = pow(2, n) - 1;
    for(int i = 0; i <limit; i++){

    }
  }
}