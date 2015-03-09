#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string arr[10000];

int n;

int main(){

  cin >> n;
  
  string min;

  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for(int i = 0; i < n - 1; i++){
    for(int j = i + 1; j < n; j++){
      if(arr[j] < arr[i]){
        min = arr[i];
        arr[i] = arr[j];
        arr[j] = min;
      }
    }
  }

  for(int i = 0; i < n; i++) {
    cout << arr[i] << endl;
  }

  return 0;
}