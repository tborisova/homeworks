#include <iostream>
#include <cassert>
#include <cstdlib>
#include "linked_list_one_link.cpp"
using namespace std;

struct node{
  int data;
  node *next;
};

class List{
  node *head, *tail, *current;

public:
  List(){
    head = tail = current = NULL;
  }

  void addToEnd(int x){
    if(tail != NULL){
      node *temp = tail;
      tail = new node;
      tail->data = x;
      temp->next = tail;
    }else{
      node *temp = new node;
      temp->data = x;
      tail = head = temp;
    }
  }

  void addToStart(int x){
    if(head != NULL){
      node *temp = head;
      head = new node;
      head->data = x;
      head->next = temp;
    }else{
      node *temp = new node;
      temp->data = x;
      tail = head = temp;
    }
  }

  void deleteElem(node *elem){
    if(elem){
      node *prev = head;
      node *next = head->next;

      if(elem == prev){
        head = next;
        delete elem;
      }else{
        while(next != NULL){
          if(elem == next){
            prev->next = elem->next;
            delete elem;
            return;
          }else{
            next = next->next;
          }
        }
      }
    }

    return;
  }

  void print(){
    node *temp = head;

    while(temp != NULL){
      cout << temp->data << endl;
      temp = temp->next;
    }
  }

  void iterStart(node *p = NULL){
    if(p){
      current = p;
    }else{
      current = head;
    }
  }

  int length(){
    iterStart();
    int n = 0;

    while(iter()){
      n++;
    }

    return n;
  }

  node *iter(){
    if(current){
      node *temp = current;
      current = current->next;
      return temp;
    }else{
      return NULL;
    }
  }
};

void sortList(List *&l){
  node *prev, *next, *swap;

  int min;
  int n = l->length();

  l->iterStart();

  for(int i = 0; i < n; i++){
    prev = l->iter();
    if(prev == NULL) return;
    next = l->iter();
    min = prev->data;
    while(next != NULL){
      cout << "CMP " << min << " " << next->data << endl;
      if(min >= next->data){
        min = next->data;
        swap = next;
      }
      next = next->next;
    }

    if(min != prev->data){
      int tmp = prev->data;
      prev->data = min;
      swap->data = tmp;
    }
    l->iterStart(prev);
    l->iter();
  }
}

int main(){
  List *l = new List();

  l->addToStart(1);
  l->addToEnd(2);
  l->addToStart(3);
  l->addToStart(4);
  l->addToEnd(5);

  cout << "list before sorting" << endl;

  l->print();

  cout << "list after sorting" << endl;

  sortList(l);
  // l->iterStart();
  // cout << (l->iter() == NULL) << endl;

  l->print();
  return 0;
}
