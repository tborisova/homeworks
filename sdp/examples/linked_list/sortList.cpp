#include <iostream>
using namespace std;
#include "linked_list_one_link.cpp"

template <typename T>
void sortList(LList<T>& l){
   if(l.empty()){
      cout << "cant sort empty list" << endl;
   }else{
      elem_link1<T> *current, *min_element;
      l.iterStart();
      current = l.iter();
      while(current->link){
        T min = current->inf;
        min_element = current;
        elem_link1<T> *q = current->link;

        while(q){
          if(q->inf < min){
            min = q->inf;
            min_element = q;
          }
          q = q->link;
        }

        min = min_element->inf;
        min_element->inf = current->inf;
        current->inf = min;
        current = current->link;
      }
   }
}

// int main(){
//   LList<int> l1;

//   l1.toEnd(2);
//   l1.toEnd(12);
//   l1.toEnd(223);
//   l1.toEnd(1);
//   l1.print();
//   sortList(l1);
//   l1.print();
// }