#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string arr[10000];

int n;

int main(){

  scanf("%d", &n);

  string min;

  for(int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
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
    printf("%d\n", arr[i]);
  }

  return 0;
}