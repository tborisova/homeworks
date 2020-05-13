// #include <cstdlib>
// #include <cassert>
// #include <iostream>
// using namespace std;

template <typename T>
struct elem{
  T inf;
  elem *link;
};

template <typename T=int>
class stack{
public:
  stack();
  ~stack();
  stack(const stack&);
  stack& operator=(const stack&);
  bool empty() const;
  void push(const T&);
  void pop(T&);
  void top(T&) const;
  void print();
  int length();
private:
  elem<T> *start;
  void copyStack(const stack&);
  void deleteStack();
};

template<typename T>stack<T>::stack(){
  start = NULL;
}

template<typename T>stack<T>::~stack(){
  deleteStack();
}

template<typename T>stack<T>::stack(const stack& st){
  copyStack(st);
}

template<typename T> stack<T>& stack<T>::operator=(const stack<T>& st){
  if (this != &st){
    deleteStack();
    copyStack(st);
  }
  return *this;
}

template<typename T> void stack<T>::copyStack(const stack<T>& st){
  if(st.start){
    elem<T> *p = st.start, *q = NULL, *s = NULL;
    start = new elem<T>;
    assert(start != NULL);
    start->inf = p->inf;
    start->link = q;
    q = start;
    p = p->link;
    while(p){
      s = new elem<T>;
      assert(s != NULL);
      s->inf = p->inf;
      q->link = s;
      q = s;
      p = p->link;
    }
    q->link = NULL;
  }
  else start = NULL;
}

template<typename T>
void stack<T>::deleteStack(){
  elem<T> *p;
  while(start){
    p = start;
    start = start->link;
    delete p;
  }
}

template<typename T> bool stack<T>::empty() const{
  return start == NULL;
}

template <typename T> void stack<T>::push(const T& s){
  elem<T>* p = start;
  start = new elem<T>;
  assert(start != NULL);
  start->inf = s;
  start->link = p;
}

template <typename T> void stack<T>::pop(T& s){
  if(start){
    s = start->inf;
    elem<T>* p = start;
    start = start->link;
    delete p;
  }else{
    cout << "stack is empty\n";
    exit(1);
  }
}

template <typename T> void stack<T>::top(T& s) const{
  if(start){
    s = start->inf;
  }else{
    cout << "stack is empty\n";
    exit(1);
  }
}

template<typename T> void stack<T>::print(){
  T x;

  while(!empty()){
    pop(x);
    cout << x << " ";
  }
  cout << endl;
}

template <typename T> int stack<T>::length(){
  int n = 0;
  elem<T>* p = start;

  while(p){
    n++;
    p = p->link;
  }

  return n;
}


template <typename T> void accumulate(T (*op)(T, T), T& null_value, stack<T>& st){
  T x;

  while(!st.empty()){
    st.pop(x);
    null_value = op(null_value, x);
  }

  return;
}

int my_int_func(int x, int y){
  return x*y;
}

int my_map_func(int x){
  return x+2;
}

template <typename T> void map(T (*func)(T), stack<T>& st, stack<T>& res){
  T x;

  while(!st.empty()){
    st.pop(x);
    res.push(func(x));
  }
}

// int main(){
//   stack<int> st, st2;
//   st.push(10);
//   st.push(20);
//   st.push(30);

//   map(my_map_func, st, st2);

//   // int x = 0;
//   // accumulate(my_int_func, x, st2);

//   st2.print(); //it empties the stack
//   // cout << x << endl;
//   return 0;
// }
