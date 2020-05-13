#include <stdlib.h>

template <typename T>
struct node{
  T inf;
  node *left, *right;
  int left_edge, right_edge;
};


template <typename T>
class tree{
  public:
    tree();
    ~tree();
    tree(const tree&);
    tree& operator=(const tree&);
    bool empty() const;
    node<T>* getRoot() const;
    T rootTree() const;
    tree leftTree() const;
    tree rightTree() const;
    void create3(const T&, const tree<T>&, const tree<T>& ); //creates tree from root + left tree + right tree
    void print() const{
      pr(root);
      cout << endl;
    }
    void create(){ //creates not empty tree through entering his nodes
      createTree(root);
    }
  private:
    node<T> *root;
    void copyTree(const tree<T>&);
    void copy(node<T>*&, node<T>* const &) const;
    void deleteTree(node<T>*&) const;
    void pr(const node<T>*) const;
    void createTree(node<T>*&) const;
};

template <typename T> tree<T>::tree(){
  root = NULL;
}

template <typename T> tree<T>::~tree(){
  deleteTree(root);
}

template <typename T> tree<T>::tree(const tree<T>& r){
  copyTree(r);
}

template <typename T> tree<T>& tree<T>::operator=(const tree<T>& r){
  if(this != &r){
    deleteTree(root);
    copyTree(r);
  }

  return *this;
}

template <typename T> void tree<T>::copyTree(const tree<T>& r){
  copy(root, r.root);
}

template <typename T> void tree<T>::copy(node<T>*& pos, node<T>* const& r) const{
  pos = NULL;

  if(r){
    pos = new node<T>;
    assert(pos != NULL);
    pos->inf = r->inf;
    copy(pos->left, r->left);
    copy(pos->right, r->right);
  }
}

template <typename T> void tree<T>::deleteTree(node<T>*& p) const{
  if(p){
    deleteTree(p->left);
    deleteTree(p->right);
    delete p;
    p = NULL;
  }
}

template <typename T> bool tree<T>::empty() const{
  return root == NULL;
}

template <typename T> node<T>* tree<T>::getRoot() const{
  return root;
}


template <typename T> T tree<T>::rootTree() const{
  return root->inf;
}

template <typename T> tree<T> tree<T>::leftTree() const{
  tree<T> t;
  copy(t.root, root->left);
  return t;
}

template <typename T> tree<T> tree<T>::rightTree() const{
  tree<T> t;
  copy(t.root, root->right);
  return t;
}

template <typename T> void tree<T>::pr(const node<T>* p) const{
  if(p){
    pr(p->left);
    // cout << p->left_edge << " ";
    cout << p->inf << " ";
    // cout << p->right_edge << " ";
    pr(p->right);
  }
}


template <typename T> void tree<T>::create3(const T& x, const tree<T>& l, const tree<T>& r){
  if(root) deleteTree(root);
  root = new node<T>;
  assert(root != NULL);
  root->inf = x;
  copy(root->left, l.root);
  copy(root->right, r.root);
}

template <typename T> void tree<T>::createTree(node<T>*& pos) const{
  T x;
  char c;

  cout << "root: "; cin >> x;
  pos = new node<T>;
  assert(pos != NULL);
  pos->inf = x;
  pos->left = NULL;
  pos->right = NULL;
  cout << "Left tree of: "<< x << " y/n? ";
  cin >> c;
  if(c == 'y'){
    pos->left_edge = rand() % 32 + 1;
    createTree(pos->left);
  }
  cout << "Right tree of: "<< x << " y/n? ";
  cin >> c;
  if(c == 'y'){
    pos->right_edge = rand() % 32 + 1;
    createTree(pos->right);

  }
}
