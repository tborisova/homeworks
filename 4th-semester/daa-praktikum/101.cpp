#include <iostream>
using namespace std;

#define MAXN 100
#define MAXK 11

int beads[MAXN][2];
int k;

long long func(int n, int i){
  if(n == 1 && i == 0) return 1;
  if(n == 1 && i == 1) return k - 1;

  if(beads[n][i] != 0){
    return beads[n][i];
  }
  long long res;
  if(i == 0){ // завършва на синьо
    res = func(n-1, 1) % 1000000007;
  }else{
    res = (((func(n-1, 0) % 1000000007) + (func(n-1, 1) % 1000000007))*(k-1)) % 1000000007;    
  }

  beads[n][i] = res;
  return res;
}

int main(){
  int n;

  scanf("%d %d", &n, &k);

  for(int i = 0; i < n; i++){  
    beads[i][0] = 0;
    beads[i][1] = 0;
  }
  cout << (((func(n, 1) % 1000000007) + (func(n, 0)) % 1000000007) %  1000000007)<< endl;
}