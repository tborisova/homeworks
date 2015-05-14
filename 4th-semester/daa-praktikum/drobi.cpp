#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

struct fraction{
  int num;
  int den;

  bool operator<(const fraction& other) const {
    return num*other.den < other.num*den;
  };
};

int gdc(int a, int b){
  while(b){
    int r = a % b;
    a = b;
    b = r;
  }

  return a;
}
int main(){

  int n;
  fraction fractions[100]; 

  scanf("%d", &n);
  int index = 0;
  for(int i = 1; i <= n - 1; i++){
    for(int j = n; j >= i+ 1; j--){
      cout << j << " " << i << " " << j % i << endl;
      if(j % i != 0){
        cout << i << " " << j << endl;
        fractions[index].num = i;
        fractions[index].den = j;
        index++;
      }
    }
  }

  sort(fractions, fractions + index);
  
  cout << "0 ";

  for(int i = 0; i < index; i++){
    cout << fractions[i].num << "/" << fractions[i].den;
    if(i != index - 1){
      cout << " ";
    }
  }
  
  return 0;
}