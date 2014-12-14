#include <cstdlib>
#include <iostream>
using namespace std;

const int MAXSIZE = 20;

template<typename T = int>
class stack{
  public:

    stack(int=MAXSIZE);
    ~stack();
    stack(const stack<T>&);
    stack<T>& operator=(const stack<T>&);
    bool empty();
    bool full();
    void push(const T&);
    void pop(T&);
    void top(T&) const;
    void print();
  private:
    int stack_size;
    int stack_top;
    T* arr;
    void copyStack(const stack<T>&);
    void deleteStack();
};

template<typename T>
stack<T>::stack(int size){
  if (size <=0) stack_size = MAXSIZE;
  else stack_size = size;
  stack_size = size;
  arr = new T[stack_size];
  assert(arr != NULL);
  stack_top = -1;
}

template<typename T>
stack<T>::stack(const stack<T>& st){
  copyStack(st);
}

template<typename T>stack<T>::~stack(){
  deleteStack();
}

template<typename T>stack<T>& stack<T>::operator=(const stack<T>& st){
  if (this != &st){
    deleteStack();
    copyStack(st);
  }

  return *this;
}

template<typename T>void stack<T>::copyStack(const stack<T>& st){
  stack_size = st.stack_size;
  stack_top = st.stack_top;
  arr = new T[stack_size];
  assert(arr != NULL);
  for(int i=0;i<=stack_top;i++){
    arr[i] = st.arr[i];
  }
}

template<typename T>void stack<T>::deleteStack(){
  delete [] arr;
}

template <typename T>bool stack<T>::empty(){
  return stack_top == -1;
}

template <typename T>bool stack<T>::full(){
  return stack_top == stack_size - 1;
}

template <typename T>void stack<T>::top(T& x) const{
  if(!empty()){
    x = arr[stack_top];
  }else{
    cout << "The stack is empty!\n";
    exit(1);
  }
}

template<typename T>void stack<T>::push(const T& x){
  if(full()){
    cout << "Stack is full!\n";
    exit(1);
  }else{
    stack_top++;
    arr[stack_top] = x;
  }
}

template<typename T>void stack<T>::pop(T &x){
  if(!empty()){
    x = arr[stack_top];
    stack_top--;
  }else{
    cout << "Stack is empty\n";
    exit(1);
  }
}

template<typename T>void stack<T>::print(){
  T x;
  while(!empty()){
    pop(x);
    cout << x << " ";
  }
  cout << endl;
}
