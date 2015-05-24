#include <iostream>
#include <cstring>
#include <map>
using namespace std;

#define N 1000000

int main(){
  long n, m;
  long upper_bound, count, fruit;
  long lower_bounds[N];
  long upper_bounds[N];

  cin >> n;

  
  cin >> upper_bound;
  lower_bounds[0] = 1;
  upper_bounds[0] = upper_bound;


  for(int i = 1; i < n; i++){
    cin >> fruit;
    lower_bounds[i] = upper_bound[i-1] + 1;
    upper_bounds[i] = upper_bound[i-1] + fruit;
  }

  int left, right, mid;
  cin >> m;
  while(m){
    cin >> fruit;
    left = 0;
    right = n -1;
    while(left <= right){
      mid = (left + right)/2;            
      if(lower_bounds[mid] <= fruit && fruit <= upper_bounds[mid]){
        cout << mid + 1 << endl;
        break;
      }
      if(lower_bounds[mid] > fruit){
        right = mid - 1;

      }else if(upper_bounds[mid] < fruit){
        left = mid + 1;
      }
    }

    m--;
  }
}