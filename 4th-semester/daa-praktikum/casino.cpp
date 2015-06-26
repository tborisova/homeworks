#include <iostream>
using namespace std;

int n;
int pull[1000];
int dyn[1000];

int play(int i){
  if(i  >= n){
    return 0;
  }

  if(dyn[i] != -1){
    return dyn[i];
  }
  
  int sum1 = play(i + 1) + pull[i];
  
  int sum2;

  if(i + 1 < n){
    sum2 = play(i + 2) + pull[i]*pull[i+1];
  }else{
    sum2 = 0;
  }
  
  dyn[i] = max(sum1, sum2);  
  cout << dyn[i] << " " << sum1 << " " << sum2 << " " << pull[i] << endl;  
  return dyn[i];
}

int main(){
  cin >> n;

  for(int i = 0; i < n;i++){
    cin >> pull[i];
    dyn[i] = -1;
  }

  cout << play(0) << endl;
}