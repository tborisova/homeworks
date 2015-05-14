#include <iostream>
#include <cstring>
#include <map>
using namespace std;

#define N 1000000

int main(){
  long n, m;
  long upper_bound = 0, count, fruit;
  long lower_bounds[N];
  long upper_bounds[N];

  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> fruit;
    upper_bound += fruit;
    lower_bounds[i] = fruit;
    upper_bounds[i] = upper_bound;
  }

  
  cin >> m;
  
  while(m){
    cin >> fruit;
    long i = 0;
    long j = n-1;

    while(1){
      if((lower_bounds[i] >= fruit && upper_bounds[j] <= fruit) ||  lower_bounds[i] == fruit || upper_bounds[j] == fruit){
        cout << i + 1 << endl;
        break;
      }else if(upper_bounds[j] > fruit){
        j--;
      }else if(lower_bounds[i] < fruit){
        i++;
      }
    }

    m--;
  }
}