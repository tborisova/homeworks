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
    upper_bound += fruit + 1;
    lower_bounds[i] = fisrt_fruit;
    upper_bounds[i] = upper_bound;
    fisrt_fruit = upper_bound + 1;
  }

  
  cin >> m;
  while(m){
    cin >> fruit;
    long left = 0;
    long right = n -1;
    long mid;

    while(left <= right){
      mid = (left + right)/2;      
      if(lower_bounds[mid] >= fruit && fruit <= upper_bounds[mid]){
        cout << mid + 1 << endl;
        break;
      }

      if(lower_bounds[mid] < fruit){
        left = mid;
      }

      if(upper_bounds[mid] > fruit){
        right = mid;
      }
    }

    m--;
  }
}