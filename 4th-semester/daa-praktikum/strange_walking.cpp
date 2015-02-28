#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main(){
  int n;

  scanf("%d", &n);

  int row, col, counter = 1;
  long int matrix[n][n];

  int pow_n = pow(double(n), 2);

  for(row = 0; row < n; row++){
    for(col = 0; col < n; col++){
      matrix[row][col] = 0;
    }
  }

  row = col = 0;

  bool go_up = false, go_down = false, go_left = true, go_rigth = false;

  while(counter <= pow_n){
    if(go_up){
      if(matrix[row][col] == 0 && row >= 0 && row <= n - 1){
        matrix[row][col] = counter;
        row--;
        counter++;
      }else{
        col--;
        row++;
        go_rigth = true;
        go_up = false;
      }
    }else if(go_rigth){
      if(matrix[row][col] == 0 && col >= 0 && col <= n - 1){
        matrix[row][col] = counter;
        col--;
        counter++;
      }else{    
        col++;
        row++;   
        go_left = true;
        go_rigth = false;
      }
    }else if(go_down){
      if(matrix[row][col] == 0 && row >= 0 && row <= n -1){
        matrix[row][col] = counter;
        row++;
        counter++;
      }else{
        col--;
        row--;
        go_down = false;
        go_up = true;
      }
    }else if(go_left){
      if(matrix[row][col] == 0 && col >= 0 && col <= (n - 1)){
        matrix[row][col] = counter;
        col++;
        counter++;
      }else{
        col--;
        row++;
        go_down = true;
        go_left = false;
      }
    }
  }

  for(row = 0; row < n; row++){
    for(col = 0; col < n; col++){
      printf("%5ld ", matrix[row][col]);
    }
    printf("\n");
  }
    printf("\n");

}