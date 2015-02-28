//Цикличен буфер (последователно представяне на опашка) се реализира със следния клас:
//Дефинирайте методите push_back() и pop(), които добавят елемент в края на буфера и изтриват елемент от началото, съответно.
template <typename T>
class CircularBuffer {
  const int CAPACITY = 32; //капацитет на буфера
  int size;
  T data[CAPACITY]; //data[0] е логически след data[CAPACITY – 1]
public:
  void push_back(const T& element);
  void pop();
};

template <typename T> void CircularBuffer<T>::push_back(const T& element){
  if(size == CAPACITY - 1){
    cout << "full\n";
    exit(1);
  }else{
    element = data[size];
    size++;
    size = size % CAPACITY;
  }
}

template <typename T> void CircularBuffer<T>::pop(const T& element){
  if(size == CAPACITY - 1){
    cout << "full\n";
    exit(1);
  }else{
    element = data[0];
    size++;
    size = size % CAPACITY;
  }
}