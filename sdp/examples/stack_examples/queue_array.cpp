#include <iostream>
#include <cstdlib>
using namespace std;

const int MAXSIZE = 20;
template <typename T = int> 
class queue{
public:
  queue(int size);
  ~queue();
  queue(const queue&);
  queue& operator=(const queue&);
  bool empty() const;
  bool full() const;
  void push(const T&);
  void pop(T&);
  void head(T&) const;
  void print();
private:
  T* arr;
  int front, rear, queue_size, queue_len;
  void copyQueue(const queue&);
  void deleteQueue();
};

template <typename T> queue<T>::queue(int size){
  if(size <= 0){
    queue_size = MAXSIZE;
  }else{
    queue_size = size;
  }
  arr = new T[queue_size];
  assert(arr != NULL);
  queue_len = 0;
  front = 0;
  rear = 0;
}

template<typename T> queue<T>::~queue(){
  deleteQueue();
}

template<typename T> queue<T>::queue(const queue<T>& q){
  copyQueue(q);
}

template<typename T> queue<T>& queue<T>::operator=(const queue<T>& q){
  if(this != &q){
    deleteQueue();
    copyQueue(q);
  }

  return *this;
}

template<typename T> bool queue<T>::empty() const{
  return queue_len == 0;
}

template<typename T> bool queue<T>::full() const{
  return queue_len == queue_size;
}

template<typename T> void queue<T>::push(const T& data) {
  if(full()){
    cout << "queue is full! Can't push!\n";
    exit(1);
  }else{
    arr[rear] = data;
    rear++;
    queue_len++;
    rear = rear % queue_size;
  }
}

template<typename T> void queue<T>::pop(T& result){
  if(empty()){
    cout << "can't take element from empty queue\n";
    exit(1);
  }else{
    result = arr[front];
    queue_len--;
    front++;
    front = front  % queue_size;
  }
}

template<typename T> void queue<T>::head(T& result) const{
  if(empty()){
    cout << "queue is empty\n";
    exit(1);
  }else{
    result = arr[front];
  }
}

template<typename T> void queue<T>::print(){
 T data;
 
 while(!empty()){
  pop(data);
  cout << data << " ";
 }

 cout  << endl;
}

template<typename T> void queue<T>::copyQueue(const queue<T>& q){
  front = q.front;
  rear = q.rear;
  queue_size = q.queue_size;
  queue_len = q.queue_len;
  arr = new T[queue_size];
  assert(arr != NULL);

  for(int i = 0; i <= queue_size; i++){
    arr[i] = q.arr[i];
  }
}

template<typename T> void queue<T>::deleteQueue(){
  delete [] arr;
}