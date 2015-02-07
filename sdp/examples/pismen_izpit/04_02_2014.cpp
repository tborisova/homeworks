
// Задача 2. Дадена е опашка от цели числа q. За нея са дефинирани функциите:

// s(x) = (x + x) % 10, ако x принадлежи на q и е равен на сбора на останалите елементи на опашката. 
///В противен случай s(x) = x.

// m(x) = (x * x) % 10, ако x принадлежи на q и е равен на произведението на останалите елементи на опашката. 
//В противен случай m(x) = x.

// Нека освен това е даден под формата на низ израз от вида
// <израз> := <цифра> | 
//                               s(<израз>) | m(<израз>) 
// Да се реализира външна функция, която пресмята стойността на израза.

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cstring>
using namespace std;
#include "stack_connected.cpp"
#include "queue_linked.cpp"
#include "cyclicList.cpp"
#include "linked_list_two_links.cpp"


// прати на дамян
int some_func(queue<int>& q,const char* s){
  int n = strlen(s);
  int i= 0;
  stack<char> stack_for_operations;
  stack<int> stack_for_operands;
  while(i < n){
    if(s[i] == 'm' || s[i] == 's'){
      cout << "will add " << s[i] << endl;
      stack_for_operations.push(s[i]);
    }else if(s[i] >= '0' && s[i] <= '9'){
      int num = s[i] - '0';
      cout << "will add " << num << endl;
      stack_for_operands.push(num);
    }else if(s[i] == ')'){
      int num;
      char ch;
      stack_for_operations.pop(ch);
      stack_for_operands.pop(num);
      cout << "pop " << ch << "  " << num << endl;
      switch(ch){
        case 's': stack_for_operands.push(q.s(num)); break;
        case 'm': stack_for_operands.push(q.m(num)); break;
      }
    }

    i++;
  }

  int result;
  stack_for_operands.pop(result);

  return result;
}

bool stange_func(DLList< cyclicList<char> >& list, const char **wordsArray, int size){
  bool matchedWords[size];
  for(int i = 0; i < size; i++){
    matchedWords[i] = false;
  }
  
  list.iterStart();
  elem_link2< cyclicList<char> >* el = list.iterNext();
  
  while(el){
    //el is one cyclic list el->inf is the cyclic list
    for(int i = 0; i < size; i++){
      el->inf.iterStart()
      elem_cyclic<char>* el_cyc = el->inf.iter();
      int lenght_of_word = strlen(wordsArray[i]);

      if(matchedWords[i] == false){
        for(int j = 0; j < lenght_of_word; i++){
          int n = 0;
          do{
            n++;
            el_cyc = el->inf.iter();
          }while(el_cyc->inf == wordsArray[i][j]);

          if(el_cyc->inf == wordsArray[i][j]){
            el_cyc = el->inf.iter();
            j++
            while(el_cyc && el_cyc->inf == wordsArray[i][j] && j < lenght_of_word){
              j++;
              el_cyc = el->inf.iter();
            }
          }

          if(j == lenght_of_word) matchedWords[i] = true;
        }
      }
    }
  }

  return true;
}

int main(){
  //zad 2
  // queue<int> q;

  // for(int i = 0; i < 10; i++){
  //   q.push(i);
  // }
  // q.push(55);
  // const char *s  = "s(m(s(3)))";
  // int res = some_func(q, s);

  // cout << res << endl;
  // return 0;

  //zad 3

  DLList< cyclicList<char> > list;

  cyclicList<char> clist;

  clist.toEnd('a');
  clist.toEnd('n');
  clist.toEnd('e');
  clist.toEnd('l');
  clist.toEnd('y');

  list.toEnd(clist);

  cyclicList<char> clist2;

  clist2.toEnd('e');
  clist2.toEnd('l');
  clist2.toEnd('e');
  clist2.toEnd('n');
  clist2.toEnd('i');

  list.toEnd(clist2);

  cyclicList<char> clist3;

  clist3.toEnd('p');
  clist3.toEnd('e');
  clist3.toEnd('t');
  clist3.toEnd('r');
  clist3.toEnd('i');
  clist3.toEnd('n');
  clist3.toEnd('a');

  list.toEnd(clist3);
  list.iterStart();

  elem_link2< cyclicList<char> > *el = list.iterNext();

  while(el){
    el->inf.print();
    el = list.iterNext();
  }

  const char *wordsArray[] = {"Asd", "asdas"};

  stange_func(list, wordsArray, 2);
  return 0;
}

/*
Задача 3.  Даден е двойносвързан списък DL от циклични списъци от символи от “a” до “z”. 
Да се напише външна функция, която по даден масив от думи проверява дали думите в него могат да се “прочетат” 
последователно от цикличните списъци в рамките на двойносвързания списък. Ако при успешно преминаване на списъка 
DL останат думи от масива, които не се проверени, то елементите на DL трябва да се проверят и в обратна посока за 
останалата част от изречението.
Забележка.
Една дума може да се прочете от цикличен списък, ако първата буква на думата се съдържа в 
цикличния списък и останалите букви могат да се прочетат като списъкът се итерира (при нужда и циклично).
 От своя страна двойносвързаният списък може да се обходи най-много веднъж в двете посоки.
Пример. Ако DL съдържа цикличните списъци от символи: a n e l y; e l e n i; p e t r i n a, 
а масивът съдържа низовете: "nely", "elen", "petri", "napet", "eleni", "lya" резултатът от изпълнението на функцията е true.
*/
