 #include <iostream>
#include <cstdio>
using namespace std;

int main(){
  int n;

  scanf("%d", &n);

  int a[n][n];
  
  int counter = 1;
  
  for(int col = 0; col < n; col++){
    for(int row = col; row < n; row++){
      if(col == row){
        a[row][col] = 0;
      }else{
        a[row][col] = counter;
        counter++;
      }
    }
  }
  
  for(int col = n - 1; col > 0; col--){
    for(int row = col - 1; row >= 0 ; row--){
      a[row][col] = counter;
      counter++;
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
}