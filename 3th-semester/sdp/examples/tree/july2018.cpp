#include <iostream>
#include <fstream>
using namespace std;


struct node{
  char inf;
  node* left;
  node* right;
  node *middle;
};

int depth(node* pos){
  if(pos == NULL) return 0;

  int n,m,r;

  n = depth(pos->left);
  m = depth(pos->right);
  r = depth(pos->middle);
  if(n > m && n > r) return n+1;
  if(m > n && m > r) return m+1;
  return r+1;
}

void readLast(node *pos, int depth){
  if(pos == NULL) return;
  if(depth == 1){
    cout << pos->inf;
  }else{
    readLast(pos->left, depth - 1);
    readLast(pos->middle, depth - 1);
    readLast(pos->right, depth - 1);
  }
}

void createTree(node*& pos, string s, int index){
  if(s[index] == '('){
    index++;
    pos = new node;
    pos->inf = s[index];
    pos->left = pos->right = pos->middle = NULL;
    index += 2;

    if(s[index] != '*'){
      createTree(pos->left, s, index);
      int i = 1;
      while(i != 0){
        index++;
        if(s[index] == ')'){
          i--;
        }else if(s[index] == '('){
          i++;
        }
      }
    }

    index += 2;

    if(s[index] != '*'){
      createTree(pos->middle, s, index);
      int i = 1;
      while(i != 0){
        index++;
        if(s[index] == ')'){
          i--;
        }else if(s[index] == '('){
          i++;
        }
      }
    }

    index += 2;

    createTree(pos->right, s, index);
  }
}

void printTree(node *root){
  if(root){
    cout << root->inf << endl;
    printTree(root->left);
    printTree(root->middle);
    printTree(root->right);
  }else{
    return;
  }
}

int main(){
  ifstream input("tree.txt");
  string s;

  getline(input, s);
  cout << s.size() << endl;
  node *temp;
  createTree(temp, s, 0);
  cout << depth(temp) << endl;
  readLast(temp, depth(temp));
  return 0;
}
