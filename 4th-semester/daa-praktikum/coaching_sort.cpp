#include <iostream>
#include <cstring>
#include <map>
using namespace std;

int main(){
  long long n;
  string str;
  map<char, int> letters;
  cin >> n >> str;

  for(char ch = '0'; ch <= '9'; ch++){
      letters[ch] = 0;
  }
  
  for(char ch = 'a'; ch <= 'z'; ch++){
    letters[ch] = 0;
  }

  for(char ch = 'A'; ch <= 'Z'; ch++){
    letters[ch] = 0;
  }

  for(int i = 0; i < n;i++){
    letters[str[i]]++;
  }

  int i = 0;
  for(char ch = '0'; ch <= '9'; ch++){
    while(letters[ch] != 0){
      str[i++] = ch;
      letters[ch]--;
    }
  }
  
  for(char ch = 'a'; ch <= 'z'; ch++){
    while(letters[ch] != 0){
      str[i++] = ch;
      letters[ch]--;
    }
  }

  for(char ch = 'A'; ch <= 'Z'; ch++){
    while(letters[ch] != 0){
      str[i++] = ch;
      letters[ch]--;
    }
  }

  cout << str << endl;
  
  return 0;
}