template <typename T>
void minqueue(queue<T>& q, T& min, queue<T>& newq){
  T x;

  q.pop(min);
  while(!q.empty()){
    q.pop(x);
    if(x < min){
      newq.push(min);
      min = x;
    }else{
      newq.push(x);
    }
  }
}

template<typename T>
void sortQueue(queue<T>& q, queue<T>& newq){

  while(!q.empty()){ 
    T min;
    queue<T> q1;
    minqueue(q, min, q1);
    newq.push(min);
    q = q1;
  }
}
