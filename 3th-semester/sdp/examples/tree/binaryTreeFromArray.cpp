#include <iostream>
#include <cassert>
using namespace std;

struct node{
  int data;
  node *left;
  node *right;
};


void buildTree(node *&root, int nodes[], int current, int n){
  if(current >= n) return;
  root = new node;
  root->data = nodes[current];

  buildTree(root->left, nodes, 2*current + 1, n);

  buildTree(root->right, nodes, 2*current + 2, n);
}

void printTree(node *&root){
  if(root){
    printTree(root->left);
    cout << root->data << endl;
    printTree(root->right);
  }
}
// k = 2, current = 1, level = 1

// k = 1, current = 2+1, level = 2

// root = 1, k = 3, current = 0;
// i = 0;
// root = 2

// void printTree(node *&root){
//   if(root){
//     cout << root->data << endl;
//     int i = 0;
//     while(root->children[i] != NULL){
//       printTree(root->children[i]);
//       i++;
//     }
//   }else{
//     return;
//   }
// }

int main(){
  int nodes[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  node *root = new node;
  int n = sizeof(nodes)/sizeof(nodes[0]);
  buildTree(root, nodes, 0, n);


  printTree(root);
  // for(int i = 0; i < 3; i++){
  //   cout << root->children[i]->data << endl;
  // }

  // for(int i = 0; i < 2; i++){
  //   cout << root->children[0]->children[i]->data << endl;
  // }

  // for(int i = 0; i < 1; i++){
  //   cout << root->children[1]->children[i]->data << endl;
  // }


  // for(int i = 0; i < 1; i++){
  //   cout << root->children[2]->children[i]->data << endl;
  // }


  // for(int i = 0; i < 2; i++){
  //   cout << root->children[0]->children[0]->data << endl;
  // }

  // cout << root->children[0]->children[0]->children[0]->data << endl;

  // cout << root->children[0]->children[0]->children[1]->data << endl;

  // cout << root->children[1]->children[0]->data << endl;
  // cout << root->children[0]->children[0]->data << endl;
  // cout << root->children[0]->children[1]->data << endl;

  // cout << root->data << endl;
  // n->data = 2;

  // node *m = new node;
  // m->data = 3;

  // node *p = new node;
  // p->data = 4;

  // n->children[0] = m;
  // n->children[1] = p;

  // cout << n->children[0]->data << " " << n->children[1]->data << endl;


  return 0;
}
