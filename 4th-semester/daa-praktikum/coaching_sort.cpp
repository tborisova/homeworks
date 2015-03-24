#include <iostream>
#include <string>
using namespace std;

int main(){
  long n;
  string str;
  int letters[260] = {};

  cin >> n >> str;

  for(int i = 0; i < n;i++){
    letters[str[i]]++;
  }

  for(char ch = '0'; ch <= '9'; ch++){
    while(letters[ch] != 0){
      cout << ch;
      letters[ch]--;
    }
  }
  
  for(char ch = 'a'; ch <= 'z'; ch++){
    while(letters[ch] != 0){
      cout << ch;
      letters[ch]--;
    }
  }

  for(char ch = 'A'; ch <= 'Z'; ch++){
    while(letters[ch] != 0){
      cout << ch;
      letters[ch]--;
    }
  }

  cout << endl;
  
  return 0;
}