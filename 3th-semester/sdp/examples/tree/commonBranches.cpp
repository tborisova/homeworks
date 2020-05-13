#include <iostream>
#include <cassert>
using namespace std;
#include "sep2019.cpp"
#include "accumulate.cpp"
#include "stack_connected.cpp"
#include "queue_linked.cpp"

typedef tree<int> intTree;


class Branch{
  public:
  node<int>* nodes[1000];
  int lenght;

  Branch(){
    lenght = 0;
  }

  void add(node<int>* v){
    nodes[lenght] = v;
    lenght++;
  }
};

void generateBranches(node<int>* p, node<int>* path[], int pathLen, queue<Branch>& st){
    if(p == NULL){
        return;
    }

    path[pathLen] = p;
    pathLen++;

    if(p->left == NULL && p->right == NULL){
      int i;
      Branch *br = new Branch();
      for (i = 0; i < pathLen; i++){
          br->add(path[i]);
      }
      st.push(*br);
    }else{
      generateBranches(p->left, path, pathLen, st);
      generateBranches(p->right, path, pathLen, st);
    }
}

int valueOfBranch(Branch branch){
  int res = 0;

  for(int i =0; i < branch.lenght - 1; i++){
    res += branch.nodes[i]->inf + branch.nodes[i+1]->inf;
  }

  return res;
}

string labelOfBranch(Branch branch){
  string res;

  for(int i =0; i < branch.lenght - 1; i++){
    res += 'A' + branch.nodes[i]->inf + branch.nodes[i+1]->inf;
  }

  return res;
}


void generateBranchesByArgs(node<int>* p, node<int>* path[], int pathLen, queue<Branch>& st, int k, string word){
    if(p == NULL){
        return;
    }

    path[pathLen] = p;
    pathLen++;

    if(p->left == NULL && p->right == NULL){
      int i;
      Branch *br = new Branch();
      for (i = 0; i < pathLen; i++){
          br->add(path[i]);
      }
      if(valueOfBranch(*br) == k && labelOfBranch(*br) == word){
        st.push(*br);
      }
    }else{
      generateBranchesByArgs(p->left, path, pathLen, st, k, word);
      generateBranchesByArgs(p->right, path, pathLen, st, k, word);
    }
}

void generateBranchesByArgsSum(node<int>* p, node<int>* path[], int pathLen, queue<Branch>& st, string word){
    if(p == NULL){
        return;
    }

    path[pathLen] = p;
    pathLen++;

    if(p->left == NULL && p->right == NULL){
      int i;
      Branch *br = new Branch();
      for (i = 0; i < pathLen; i++){
          br->add(path[i]);
      }
      if(labelOfBranch(*br) == word){
        st.push(*br);
      }
    }else{
      generateBranchesByArgsSum(p->left, path, pathLen, st, word);
      generateBranchesByArgsSum(p->right, path, pathLen, st, word);
    }
}

void commonBranchesBetter(intTree* tree, node<int>* v1, node<int>* v2, int k){
  node<int>* path1[1000];
  node<int>* path2[1000];
  queue<Branch> st1;
  queue<Branch> st2;
  int ar1[1000];
  int ar2[1000];
  int size1 = 0;
  int size2 = 0;
  int val;

  generateBranches(v1, path1, 0, st1);

  Branch br1;
  Branch br2;

  while(!st1.empty()){
    st1.pop(br1);

    generateBranchesByArgs(v2, path2, 0, st2, k - valueOfBranch(br1), labelOfBranch(br1));

    while(!st2.empty()){
      st2.pop(br2);
      cout << labelOfBranch(br1) << endl;
    }
  }
}

int sumVal(intTree* tree, node<int>* v1, node<int>* v2){
  node<int>* path1[1000];
  node<int>* path2[1000];
  queue<Branch> st1;
  queue<Branch> st2;
  int ar1[1000];
  int ar2[1000];
  int size1 = 0;
  int size2 = 0;
  int val;
  int result = 0;

  generateBranches(v1, path1, 0, st1);

  Branch br1;
  Branch br2;

  while(!st1.empty()){
    st1.pop(br1);

    generateBranchesByArgsSum(v2, path2, 0, st2, labelOfBranch(br1));

    while(!st2.empty()){
      st2.pop(br2);
      result += valueOfBranch(br1) + valueOfBranch(br2);
    }
  }

  return result;
}


int main(){
  intTree t;
  node<int>* path[1000];
  stack<int> st;
  queue<Branch> stBr;

  t.create();
  commonBranchesBetter(&t, t.getRoot()->left, t.getRoot()->right, 10);

return 0;
}
