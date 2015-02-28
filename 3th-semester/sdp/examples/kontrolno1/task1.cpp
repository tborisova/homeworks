// В текстов файл са записани данни за служители на фирма. Всеки ред се състои от трите имена на служителя, състоящи се от малки и големи
// латински символи, разделени с интервали, година на постъпване на служителя на работа и година на напускане. Ако служителят е все още на
// работа, се записва -1 като година на напускане. Сумарно дължината на име на служител не надвишава 128 символа.

// Прочетете данните от файла и създайте двоичен файл, съдържащ същите данни. Данните трябва да са записани в двоичния файл по
// такъв начин, че да е възможно да се възстановят напълно при четене на двоичния файл.

// Отпечатайте всеки ред от текстовия файл на екрана, като колони, подравнени вляво.
// примерен вход:
// Georgi Georgiev Zahariev 1989 -1
// Ivan Petkov Ivanov 2010 2010
// примерен изход:
// Georgi Georgiev Zahariev          1989 -1
// Ivan Petkov Ivanov                    2010 2010

#include <string.h>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){

  char ch;

  ifstream fin("file1.txt", ios::binary);

  ofstream fout("file2", ios::binary);

  if (fin && fout){
    
    while(fin){

      fout.put(fin.get());
    
    }
  }
  fin.close();
  fout.close();

  ifstream fin2("file1.txt");
  char first_name[43];
  char middle_name[43];
  char last_name[43];
  char start_year[4];
  char end_year[4];

  while(fin2){
    fin2 >> first_name;
    fin2 >> middle_name;
    fin2 >> last_name;
    fin2 >> start_year;
    fin2 >> end_year;
    cout.setf(ios::left);
    cout << left << first_name <<  " " << middle_name << " " << last_name << " " << start_year << " " << end_year << endl;
    // cout.width(128 - strlen(first_name) - strlen(last_name) - strlen(middle_name));  
    // cout << " " << start_year << " " << end_year << endl;
  }

  fin2.close();
}