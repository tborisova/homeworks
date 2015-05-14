#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;


int main(){
  char arr[10000][10000001];
  int n;
  char min[10000001];
  scanf("%d", &n);

  for(int i = 0; i < n; i++) {
    cin >> min;
    strcpy(arr[i], min);
  }

  for(int i = 0; i < n - 1; i++){
    for(int j = i + 1; j < n; j++){
      if(strcmp(arr[j], arr[i]) < 0){
        strcpy(min, arr[i]);
        strcpy(arr[i], arr[j]);
        strcpy(arr[j], min);
      }
    }
  }

  for(int i = 0; i < n; i++) {
    cout << arr[i] << endl;
  }

  return 0;
}