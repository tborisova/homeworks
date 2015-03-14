#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
using namespace std;
 
 int get_num(char c){
  if(c >= 'A' && c <= 'Z'){
    return 37 + (c - 'A');
  }else if(c >= 'a' && c <= 'z'){
    return 11 + (c - 'a');
  }else if(c >= '0' && c <= '9'){
    return 1 + (c - '0');
  }
}

int compare (const void * a, const void * b)
{
  return ( get_num(*(char*)a) - get_num(*(char*)b) );
}

int main(){
  int n;
  
  scanf("%d", &n);
  string str, str2;
  cin >> str;
  
  qsort(str, n, sizeof(char), compare);

  cout << str << endl;
}