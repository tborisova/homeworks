#include "linked_list_one_link.cpp"

template <typename T=int>
class stack : public LList<T>{
public:
  stack();
  ~stack();
  stack(const stack&);
  stack& operator=(const stack&);
  void pop(T& x);
  void push(const T& x);
  void top(T& x);
  bool empty();
  int length();
  void print();
  void iterStart(elem_link1<T>* p=NULL);
  elem_link1<T>* iter();
};

template <typename T> stack<T>::stack() : LList<T>(){}

template <typename T> stack<T>::~stack(){}

template <typename T> stack<T>::stack(const stack<T>& r) : LList<T>(r){}

template <typename T> stack<T>& stack<T>::operator=(const stack<T>& r){
  if(this != &r){
    LList<T>::operator=(r);
  }

  return *this;
}

template <typename T> bool stack<T>::empty(){
  return LList<T>::empty();
}

template <typename T> void stack<T>::push(const T& x){
  if (!empty()){
    iterStart(NULL);
    elem_link1<T> *p = iter();
    LList<T>::insertBefore(p, x);
  }else{
    LList<T>::toEnd(x);
  }
}

template <typename T> void stack<T>::pop(T& x){
  if (!empty()){
    iterStart(NULL);
    elem_link1<T> *p = iter();
    LList<T>::deleteElem(p, x);
  }else{
    cout << "cant pop from empty stack" << endl;
    exit(1);
  }
}

template <typename T> void stack<T>::iterStart(elem_link1<T> *p){
  LList<T>::iterStart(p);
}

template <typename T> void stack<T>::top(T& x){
  if (!empty()){
    iterStart(NULL);
    elem_link1<T> *p = iter();
    x = p->inf;
  }else{
    cout << "can't top from empty stack" << endl;
    exit(1);
  }
}

template <typename T> void stack<T>::print(){
  LList<T>::print();
}

template <typename T> int stack<T>::length(){
  LList<T>::length();
}

template <typename T> elem_link1<T>* stack<T>::iter(){
  LList<T>::iter();
}

// int main(){
//   stack<int> st;
//   st.push(10);
//   st.push(20);
//   st.push(30);

//   stack<int> st1 = st, st2;
//   st2 = st1;
//   st.print();
//   st2.print();
//   cout << st.length() << endl;
//   return 0;
// }
