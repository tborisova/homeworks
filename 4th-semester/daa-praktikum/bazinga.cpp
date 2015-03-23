#include <iostream>
#include <string>
#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
  string str;

  // string word = "bazinga";
  map<char, int> word;

  word['b'] = 0;
  word['a'] = 0;
  word['z'] = 0;
  word['i'] = 0;
  word['n'] = 0;
  word['g'] = 0;
  
    while(cin >> str){
      for(int i = 0; i < str.size(); i++){
        word[(char)tolower(str[i])]++;
      }
    }
    int array[6] = { word['b'], word['a'], word['z'], word['i'], word['n'],word['g']};

    // for(int i = 0; i < 7; i++){
    //   cout << array[i] << endl;
    // }
    int min = *min_element(array, array + 6);
    
    while(word['a'] > 2*min && min > 0){
      min--;
    }

    cout << min << endl;
  
  // }
}