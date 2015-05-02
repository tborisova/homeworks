#include <iostream>
#include <string>
#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
  string str;

  map<char, int> word;

  word['b'] = 0;
  word['a'] = 0;
  word['z'] = 0;
  word['i'] = 0;
  word['n'] = 0;
  word['g'] = 0;
  
  
    while(cin >> str){
      for(int i = 0; i < str.size(); i++){
        word[tolower(str[i])]++;
      }
    }


    int array[5] = { word['b'], word['z'], word['i'], word['n'],word['g']};

    int min = *min_element(array, array + 5);

    word['a'] /= 2;
    // min = word['a'];

    if(min > word['a']){
      cout << word['a'] << endl;
    }else{
      cout << min << endl;
    }
}