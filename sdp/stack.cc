#include <iostream>
using namespace::std;

class Node{
  int data;
  Node* next;

public:
  //kopirasht constructor
  //operator =
  Node(int d, Node* n) : data(d), next(n) {}
  
  int get_data(){
    return data;
  }

  Node* get_next(){
    return next;
  }
};

class StackError{};

class Stack{
  Node* top; //- posledniq element v steka;

public:
  Stack(){
      top = new Node(0, NULL);
  }

  ~Stack() {
    while(!empty()) {
      pop();
    }

    delete top;
  }
  
  int pop() {
    if(empty()) {
        throw new StackError();
    }
    
    Node* temp = top;
    int data = temp->get_data();
    
    top = temp->get_next();
    
    delete temp;
    
    return data;
  }

  //int peak(){}
  
  void push(int data) {
    Node new_node = new Node(data, top);
    top = &new_node;
  }

  bool empty() {
    return top == NULL;
  }
};


int main(){

  return 0;
}