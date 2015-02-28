// Да се дефинира функция, която заменя всеки израз от вида (a+b).(a-b) в даден текстов файл с низа (a^2-b^2). 
// Чрез a и b са означени произволни цели числа.

#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <regex>
#include <iterator>
using namespace std;


int main()
{
  regex pattern ("((\\d)+(\\d)).(\\d-\\d)");
  string inbuf;
  fstream input_file("demo.txt", ios::in);
  ofstream output_file("result.txt");

  while (!input_file.eof())
  {
      getline(input_file, inbuf);
      string res;
      regex_replace(back_inserter(res), inbuf.begin(), inbuf.end(), pattern, "jjjjjjj");
      output_file << res << endl;
  }
  input_file.close();
  output_file.close();
}