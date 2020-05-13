#include <iostream>
#include <fstream>
using namespace std;


struct node{
  int inf;
  node* next;
  node* k_next;
};

class list{


  public:
    node *head;
    node *tail;
    node *current;
    node *needsK;
    int currentInsertedPosition;
    int k;
    list(int x){
      needsK = NULL;
      currentInsertedPosition = 0;
      head = tail = current = NULL;
      k = x;
    }

    void add(int x){
      node *temp = tail;
      tail = new node();
      tail->inf = x;
      tail->next = NULL;
      if(temp){
        temp->next = tail;
        if(currentInsertedPosition == k){
          needsK->k_next = tail;
          needsK = tail;
          currentInsertedPosition = 1;
        }else{
          currentInsertedPosition++;
        }
      }else{
        head = tail;
        if(head->inf % k == 0){
          needsK = head;
        }
        currentInsertedPosition = 1;
      }
    }

    node *iter(){
      node *p = current;
      if(current) current = current->next;
      return p;
    }

    void iterStart(node *p){
      if(p) current = p;
      else current = head;
    }
};

int main(){
  string myText;
  int number;
  int numbers[1000];
  list *l = new list(3);
  int i = 0;
  ifstream myfile("filename.txt", ios_base::in);

  while (myfile >> number) {
    numbers[i] = number;
    i++;
  }

  myfile.close();

  for(int j = 0; j < i; j++){
    l->add(numbers[j]);
  }

  l->iterStart(l->head);

  node *iter = l->iter();

  while(iter != NULL){
    if(iter->k_next != NULL){
      cout << iter->k_next->inf << endl;
    }
    // cout << iter->inf << endl;
    iter = l->iter();
  }

  return 0;
}
