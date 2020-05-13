// C++ program to merge k sorted arrays of size n each
#include <iostream>
#include <cassert>
#include <cstdlib>
#include "linked_list_one_link.cpp"
using namespace std;

struct LLNode {
  LList<int> *list;
  LLNode *link;
};

class LLList{
  LLNode *head, *tail, *current, *currentSorted;

public:
  LLList(){
    head = tail = NULL;
  }

  void add(LList<int> *list){
    if(tail != NULL){
      LLNode *temp = tail;
      tail = new LLNode();

      tail->list = list;
      temp->link = tail;
    }else{
      LLNode *temp = new LLNode();
      temp->list = list;
      temp->link = NULL;

      head = tail = temp;
    }
  }

  void print(){
    LLNode *temp = head;
    while(temp != NULL){
      temp->list->print();
      temp = temp->link;
    }
  }

  void iterStart(LLNode *l=NULL){
    if(l){
      current = l;
    }else{
      current = head;
    }
  }

  LLNode *iter(){
    LLNode *temp = current;

    if(current) current = current->link;

    return temp;
  }
};


LList<int>* sortLists(LList<int> *l1, LList<int> *l2){
  LList<int>* result = new LList<int>();

  if(l1 == NULL) return l2;
  if(l2 == NULL) return l1;


  l1->iterStart();
  l2->iterStart();

  elem_link1<int>* it1 = l1->iter();
  elem_link1<int>* it2 = l2->iter();

  while(it1 != NULL && it2 != NULL){
    if(it1->inf <= it2->inf){
      result->toEnd(it1->inf);
      it1 = l1->iter();
    }else{
      result->toEnd(it2->inf);
      it2 = l2->iter();
    }
  }

  if(it1 != NULL){
    while(it1 != NULL){
      result->toEnd(it1->inf);
      it1 = l1->iter();
    }

  }else if(it2 != NULL){
    while(it2 != NULL){
      result->toEnd(it2->inf);
      it2 = l2->iter();
    }
  }

  return result;
}

LList<int>* mergeKLists(LLList* l)
{
  LLNode *iter;
  LList<int> *result = new LList<int>();

  l->iterStart();
  LLNode *start = l->iter();

  if(start->list->sorted()){
    result = start->list;
  }else{
    iter = l->iter();

    while(iter != NULL){
      if(iter->list->sorted()){
        result = iter->list;
        break;
      }
      iter = l->iter();
    }
  }


  iter = l->iter();

  while(iter){

    if(iter->list->sorted()){
      result = sortLists(result, iter->list);
    }

    iter = l->iter();
  }

  return result;
}

// Driver program to test above functions
int main()
{

  LList<int> l1, l2, l3;

  cin >> l1;
  cin >> l2;
  cin >> l3;

  LLList *l = new LLList();

  l->add(&l1);
  l->add(&l2);
  l->add(&l3);

  LList<int> *ll = mergeKLists(l);

  cout << "PRINGING" << endl;
  ll->print();


  return 0;
}
