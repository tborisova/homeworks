#include <iostream>
#include <fstream>
using namespace std;


struct node{
  int inf;
  node* next;
  node* k_next;
};

class list{


  public:
    node *head;
    node *tail;
    node *current;
    int k;
    list(int x){
      head = tail = current = NULL;
      k = x;
    }

    void readList(string filename){
      int numbers[1000];
      int number;
      int i = 0;
      ifstream myfile(filename, ios_base::in);

      while (myfile >> number) {
        numbers[i] = number;
        i++;
      }

      myfile.close();

      for(int j = 0; j < i; j++){
        add(numbers[j]);
      }

      iterStart(head);
      node *temp = iter();
      int currentIndex = 0;
      while(temp != NULL){
        if((currentIndex == 0 || k % currentIndex == 0) && currentIndex != 1){
          node *secondTemp = iter();

          for(int l = 1; l < k; l++){
            secondTemp = iter();
          }
          temp->k_next = secondTemp;

          iterStart(temp);
          temp = iter();
        }
        currentIndex++;
        temp = iter();
      }
    }

    void add(int x){
      node *temp = tail;
      tail = new node();
      tail->inf = x;
      tail->next = NULL;
      if(temp){
        temp->next = tail;
      }else{
        head = tail;
      }
    }

    bool member(int x){
      node *starK = head;
      node *prevK = head;

      while(true){
        if(starK->inf < x && starK->k_next != NULL){
          prevK = starK;
          starK = starK->k_next;
        }else{
          break;
        }
      }

      iterStart(prevK);

      node *it = iter();

      while(it != starK){
        if(it->inf == x){
          return true;
        }else{
          it = iter();
        }
      }

      return false;
    }

    void iterStart(node *p){
      if(p != NULL){
        current = p;
      }else{
        current = head;
      }
    }

    node *iter(){
      node *p = current;
      if(current) current = current->next;
      return p;
    }
};

int main(){
  list *l = new list(3);
  l->readList("filename.txt");

  // l->iterStart(l->head);

  // node *iter = l->iter();

  // while(iter != NULL){
  //   if(iter->k_next != NULL){
  //     // cout << iter->k_next->inf << endl;
  //   }
  //   // cout << iter->inf << endl;
  //   iter = l->iter();
  // }
  cout << l->member(11) << endl;
  return 0;
}
