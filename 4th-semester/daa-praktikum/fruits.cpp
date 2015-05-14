#include <iostream>
#include <cstring>
#include <map>
using namespace std;

#define N 10000

int main(){
  long n, m;
  long upper_bound = 0, count, fruit;
  long fisrt_fruit = 1;
  long lower_bounds[N];
  long upper_bounds[N];

  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> fruit;
    upper_bound += fruit;
    lower_bounds[i] = fisrt_fruit;
    upper_bounds[i] = upper_bound;
    fisrt_fruit = upper_bound + 1;
  }

  
  cin >> m;
  // cout << "here" << endl;
  while(m){
    cin >> fruit;
    long i = 0;
    long j = n-1;

    while(1){
      cout << " " << fruit << " " << lower_bounds[i] << " " << upper_bounds[j] << endl;
      if((lower_bounds[i] >= fruit && fruit <= upper_bounds[j]) ||  lower_bounds[i] == fruit || upper_bounds[j] == fruit){
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