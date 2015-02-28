#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;
#include "linked_list_one_link.cpp"
#include "graph.cpp"

template <typename T>
int sumOfVertices(Graph<T>& g){
  
}

template <typename T> void create_graph(graph<T> &g){
  char c;
  do{
    cout << "top_of_graph: ";
    T x;cin >> x;
    g.addTop(x);
    cout << "Top y/n ? ";cin >> c;
  }while(c == 'y');

  cout << "ribs: \n";
  do{
    cout << "start top: ";
    T x; cin >> x;
    cout << "end top: ";
    T y; cin >> y;
    g.addRib(x, y);
    cout << "next: y/n? "; cin >> c;
  }while(c == 'y');
}

typedef graph<int> intGraph;
int main(){
  intGraph g;
  create_graph(g);
  g.print();
  return 0;
}