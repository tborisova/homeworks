//////////////////////////// VARIANT 1
// Задача 1 (4 точки). Да се дефинират член-функциите: 
//void push(const T&x), включваща елемента x в неявания стек и void pop(T&),
//изключваща елемент от неявния стек и записваща го в параметъра x на шаблона 
//на класа stack, реализиращ свързано представяне на стек с елементи от тип Т.

template <typename T> void stack<T>::push(const T &x){
  elem<T>* p = start;
  start = new elem<T>;
  assert(start != NULL);
  start->inf = s;
  start->link = p;
}

template <typename T> void stack<T>::pop(T& x){
  if(start){
    elem<T>* p = start;
    x = start->inf;
    start = start->link;
    delete p;
  }else{
    cout << "cant pop from empty stack"
  }
}

/* Задача 2 (4 точки). Да се дефинират следните член-функции на шаблона на 
класа queue, представен свързано: void copyQueue(const queue<T>& r) – 
копира опашката r в подразбиращата се опашка и void pop(T& x), 
изключваща елемент от неявната опашка и записваща го в параметъра x.
*/

template <typename> void copyQueue(const queue<T>& r){
  head = rear = NULL;

  elem_q<T> *temp = q.front;
  while(temp){
    push(temp->inf);
    temp = temp->link;
  }
}

template <typename T> void queue<T>::pop(T& data){
  if (empty()){
    cout << "can't pop from empty queue\n";
    exit(1);
  }else{
    data = front->inf;
    elem_q<T>* temp = front;
    if(temp == rear){
      rear = front = NULL;
    }
    else front = temp->link;
    delete temp;
  }
}

//Задача 3 (4 точки). Предефинирайте операторите >> и << за въвеждане и извеждане на свързан списък, представен с две връзки.
template <typename T> ostream& operator<<(ostream& stream, const DLList<T>& list){
  list.iterStart();
  elem_link2<T>* current = list.iter();

  while(current){
    stream << current->inf << " ";
  }

  stream << endl;

  return stream;
}

template <typename T> istream& operator>>(istream& stream, DLList<T>& list){
  T x;
  char ch = 'y';

  while(ch == 'y'){
    cout << "Enter element: ";
    stream >> x;
    list.toEnd(x);
    cout << "Continue? (y/n): ";
    cin >> ch;
  }
  
  return stream;
}

/*
Задача 4. (5 точки) Дефинирайте член-функцията void deleteBefore(elem_link1<T>* p, T& x) на 
шаблона на класа LList, реализиращ свързан списък, представен с една връзка. 
Член-функцията изключва елемента пред елемента, сочен от указателя p и го запомня в параметъра x. 
Предполагасе, че p е ненулев указател и сочи съществуващ елемент на неявния списък.
*/

template <typename T> void deleteBefore(elem_link1<T>* p, T& x){
  if(start == p || start == end){
    cout << "cant delete before start"  
  }else{
    elem_link2<T> *el = start;

    while(el->link->link != p) { el = el->link } // we want to take the element that is before the elemnt we want to deleete

    x = el->link->inf;
    el->link = p;
    delete el;
  }
}

/*
Задача 5 (5 точки). Даден е свързан списък (представен с две връзка) от цели числа. 
Дефинирайте рекурсивна функция, която проверява дали елементите на списъка са 
симетрични относно средата на списъка.*/

template <typename T> bool symetric(DLList<T>& list){
  if(list.empty() || list.length() == 1) return true;

  list.iterStart();
  list.iterEnd();
  elem_link2<T>* next = list.iterNext();
  elem_link2<T>* prev = list.iterPrev();

  if(next->next == prev){
    return true;
  }
  T x,y;
  list.deleteElem(next, x);
  list.deleteElem(prev, y);
  return symetric(list) && x == y; 
}

/*Задача 6 (4 точки). Да се дефинират член-функциите за работа с итератора на 
шаблона на класа cyclicList, реализиращ цикличен свързан списък с една връзка.
*/

template <typename T> void cyclicList<T>::iterStart(elem_cyclic<T>* p){
  if(p){
    current = p;
  }else if(start){
    current = start->link;
  }else{
    current = NULL;
  }
}

template <typename T> elem_cyclic<T>* cyclicList<T>::iter(){
  if(current){
    elem_cyclic<T>* p = current;
    if(current == start) current = NULL;
    else current = current->link;
    return p;
  }else{
    return NULL;
  }
}

/*Задача 7 (3 точки). Да се напише шаблон на функцията от по-висок ред accumulate за стек.*/

template <typename T> T accumulate(T (*op)(T, T), T& null_value, stack<T>& st){
  T x;

  while(!st.empty()){
    null_value = op(null_value, x);
  }

  return null_value;
}


//////////////////
/*Задача 1 (4 точки). Да се дефинират член-функциите: void push(const T&x), 
включваща елемента x в неявания стек и void pop(T&), изключваща елемент от неявния стек и 
записваща го в параметъра x на шаблона на класа stack, реализиращ последователно представяне на стек с елементи от тип Т.*/

template <typename> void stack<T>::push(const T&x){
  if(full()){
    cout << "stack is full! can't add new elements!" << endl;
  }else{
    arr[stack_top++] = x;
  }
}

template <typename> void stack<T>::pop(T&x){
  if(empty()){
    cout << "stack is empty! can't pop!" << endl;
  }else{
    x = stack[--stack_top];
  }
}

/*Задача 2 (4 точки). Да се дефинират следните член-функции на шаблона на класа queue, представен свързано: 
void deleteQueue() – изтрива подразбиращата се опашка и queue& operator=(const queue&), реализиращ присвояване.
*/

template <typename T> void queue<T>::deleteQueue(){
  T x;
  while(!empty()){
    pop(x);
  }
}

template <typename T> queue<T>& queue<T>::operator=(const queue<T>& q){
  if(this != &q){
    deleteQueue();
    copyQueue(q);
  }

  return *this;
}

template <typename T> void queue<T>::copyQueue(const queue<T>& q){
  elem_q<T> *current = q.front;
  front = rear = NULL;
  while(current){
    push(q->inf);
    current = current->link;
  }
}

//Задача 3 (4 точки). Предефинирайте операторите >> и << за въвеждане и извеждане на свързан списък, представен с една връзка.

template <typename T> ostream& operator<<(ostream& stream, LList<T>& list){
  list.iterStart();
  elem_link1<T>* el = list.iter();

  while(el){
    stream << el->inf << " ";
    el = list.iter();
  }

  return stream;
}


template <typename T> istream& operator>>(istream& stream, LList<T>& list){
  char ch = 'y';
  T x;

  while(ch == 'y'){
    cout << "Enter el: ";
    stream >> x;
    list.insert(x);
    cout << "Continue?(y/n): ";
    stream >> ch;
  }

  return stream;
}

/*
Задача 4. (5 точки) Дефинирайте член-функцията void deleteAfter(elem_link1<T>* p, T& x) на 
шаблона на класа LList, реализиращ свързан списък, представен с една връзка. 
Член-функцията изключва елемента след елемента, сочен от указателя p и го 
запомня в параметъра x. Предполагасе, че p е ненулев указател и сочи съществуващ елемент на неявния списък
*/

template <typename T> void LList<T>::deleteAfter(elem_link1<T>* p, T& x){
  x = p->link->inf;
  elem_link1<T>* elem_to_delete = p->link;

  if(p->link == end){
    end = p;
    p->link = NULL;
  }else{
    p->link = elem_to_delete->link;
  }

  delete elem_to_delete;
}

/*Задача 5 (5 точки). Даден е непразен свързан списък (представен с две връзка) с четен брой цели числа. 
Да се дефинира рекурсивна функция, която проверява дали елементите на първата половина списъка са 
строго монотонно растящи, а елементите от втората половина – монотонно намаляващи.
*/
// 1 2 3 4 7 6 5 4
template <typename T> bool monotonno(DLList<T>& list){
  if(list.empty()) return true;

  list.iterStart();
  list.iterEnd();

  elem_link2<T> *next = list.iterNext(), *prev = list.iterPrev();

  T x, y;
  list.deleteElem(next, x);
  list.deleteElem(prev, y);

  bool res = monotonnoHelper(list, x, y);

  return res;
}
template <typename T> bool monotonnoHelper(DLList<T>& list, T x, T y){
  if(list.empty()) return true;
  list.iterStart();
  list.iterEnd();

  elem_link2<T> *next = list.iterNext(), *prev = list.iterPrev();
  
  if(next->next == prev) return true;

  T z, t;
  list.deleteElem(next, z);
  list.deleteElem(prev, t);
  return monotonnoHelper(list, z, t) && (x < z) && (t > y);
}


/* 
Задача 6 (4 точки). Дефинирайте следните член-функции на шаблона на класа cyclicList, 
реализиращ цикличен свързан списък, представен с една връзка: void insert(const T&), 
която включва указания чрез параметъра елемент като първи в подразбиращия се 
цикличен свързан списък и void print()const, която извежда елементите на подразбиращия се цикличен свързан списък.
*/

template <typename T> void cyclicList<T>::insert(const T&){
  elem_link1<T>* new_el = new elem_link1<T>;
  new_el->inf = x;  
  if(start == NULL){
    start = new_el;
  }else{
    new_el->link = start->link;
  }

  start->link = new_el;
}

template <typename T> void cyclicList<T>::print(){
  if(!empty()){
    elem_cyclic<T> *p = start;
    if(p){
      do{
        cout << p->inf << " ";
        p = p->link;
      }while(p != start);
    }
    cout << endl;
  }
}


//Задача 7 (3 точки). Да се напише шаблон на функцията от по-висок ред map за стек.
template <typename T> void map(T (*func)(T), stack<T>& st, stack<T>& res){
  T x;

  while(!st.empty()){
    st.pop(x);
    res.push(func(x));
  }
}
