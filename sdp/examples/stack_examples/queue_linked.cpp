
template <typename T = int>
struct elem_q{
  T inf;
  elem_q<T>* link;
};

template <typename T = int>
class queue{
public:
  queue();
  ~queue();
  queue(const queue&);
  queue& operator=(const queue&);
  bool empty();
  void push(const T&);
  void pop(T&);
  void head(T&) const;
  void print();
  int length();
private:
  elem_q<T> *front;
  elem_q<T> *rear;
  void copyQueue(const queue&);
  void deleteQueue();
};

template<typename T> queue<T>::queue(){
  front = rear = NULL;
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

template<typename T> bool queue<T>::empty(){
  return rear == NULL;
}

template<typename T> void queue<T>::push(const T& data){
  elem_q<T> *new_element = new elem_q<T>;
  assert(new_element != NULL);

  new_element->inf = data;
  new_element->link = NULL;
  if(rear) rear->link = new_element;
  else front = new_element;

  rear = new_element;
}

template<typename T> void queue<T>::pop(T& data){
  if (empty()){
    cout << "can't pop from empty queue\n";
    exit(1);
  }else{
    data = front->inf;
    elem_q<T>* temp = front;
    if(temp == rear){
      rear = front = NULL;
    }
    else front = front->link;
    delete temp;
  }
}

template <typename T> void queue<T>::head(T& data) const{
  if(empty()){
    cout << "empty queue\n";
    exit(1);
  }else{
    data = front->inf;
  }
}

template<typename T>void queue<T>::print(){
  T data;

  while(!empty()){
    pop(data);
    cout << data << " ";
  }
  cout << endl;
}

template<typename T>int queue<T>::length(){
  T data;
  int n = 0;

  while(!empty()){
    n++;
    pop(data);
  }

  return n;
}

template <typename T> void queue<T>::copyQueue(const queue<T>& q){
  rear = front = NULL;

  elem_q<T> *temp = front;
  while(temp){
    push(temp->inf);
    temp = temp->link;
  }  
}

template <typename T> void queue<T>::deleteQueue(){
  T data;

  while(!empty()){
    pop(data);
  }
}