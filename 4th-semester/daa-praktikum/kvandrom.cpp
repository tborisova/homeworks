#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  long int palindromic_squares[39] = { 1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004 };

  vector<long int> square_roots(palindromic_squares, palindromic_squares + 39);

  int counter = 0;
  long int a, b;

  // scanf("%ld", &a);
  // scanf("%ld", &b);


  // for(int i = 0; i < 39; i++){
  //   if(palindromic_squares[i] >= a && palindromic_squares[i] <= b){
  //     counter++;
  //   }
  //   if(binary_search(square_roots.begin(), square_roots.end(), sqrt(a))){
  //     counter++;
  //   }
  // }

  printf("%ld", 4004009004004);
}