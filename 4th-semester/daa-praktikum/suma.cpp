#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 1000000

int main(){
  int numbers[MAXN], i,j, temp, number, n,m;

  cin >> n >> m;

  for(int i = 0; i < n; i++){
    cin >> numbers[i];
  }

  sort(numbers, numbers + n);

  while(m){
    cin >> number;
    i = 0;
    j = n -1;

    while(1){
      if(i == j){
        cout << "NO" << endl;
        break;
      }

      temp = numbers[i] + numbers[j];
      if(temp > number){
          j--;
      }else if(temp < number){
          i++;
      }else{
        cout << "YES" << endl;
        break;
      }
    }  
  
    m--;
  }

}