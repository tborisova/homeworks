#include <iostream>
#include <map>
#include <cstring>
using namespace std;

#define MAXN 200000

int main(){
  int women[101]; 
  int man[101]; 
  int height, n, counter = 0;
  char sex;

  for(int i = 0; i <= 100; i++){
    women[i] = 0;
    man[i] = 0;
  }

  cin >> n;

  while(n){
    cin >> height >> sex;
    if(sex == 'W'){
      women[height - 120] += 1;
    }else{
      man[height - 120] += 1;
    }
    n--;
  }

  for(int i = 0; i <= 100; i++){
    counter += min(women[i], man[i]);
  }

  cout << counter << endl;

  if(counter){
    for(int i = 100; i >=  0; i--){
      if(women[i] != 0 && man[i] != 0){
        cout << i + 120 << " " << min(women[i], man[i]) << endl;
      }
    }
  }
 
 return 0;
}