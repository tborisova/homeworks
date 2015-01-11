template <typename T> bool member(const T& a,const binOrdTree<T>& t){
  if(t.empty()){
    return false;
  }else{
    if(a == t.rootTree()) return true;
    if(a < t.rootTree()) return member(t.leftTree());
    return member(a, t.rightTree());
  }
}