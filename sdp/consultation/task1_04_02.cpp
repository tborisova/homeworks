#include <iostream>
#include <cstdlib>
using namespace std;

struct meow{
  stize_t nl;
  stize_t size;
  char a;
};


// това е първа задача с файла от 04–02 писмения изпит
// четем ред по ред от файла с getline и имаме max_line, number_of_row - nl, и правим структури. После записваш в бинарен файл структурите
// write(reinterpret_cast<char*>(&struct_instance), sizeof(meow))
// nl - ред на структурите ввъв файла, това са отместванията и ползваме tellg seekg
// nl*sizeof(meow) = къде се намира стуктурата във файла
// имаме максимална стукрута, която като черем от файла, запазваме max_struct, и после се връщаме да променим a да стане+

// списък от cyclic и дума - дали може да бъде намерена
// задачата с елени
bool foo(cyclicList<char>& x, char *w){
  
}

//check tree - в друг файл

tree<char*> t
typedef queue<node_t*> queue_node_pointer;

queue_node_pointer f = new queue<node_t*>;
f.enqueue(&t);
l.push(t)

while(!f.empty()){
  f.dequeue(&t);
  
}

//основното:
// като имаш обхождане в дълбочина се ползва стек за елементите, а обхождане в ширина - опашка. рекурсията в ооп не е готина