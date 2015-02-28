template <typename T> tree<T> map(T (*f)(T), const tree<T>& t){
  tree<T> t1;

  if(t.empty()){
    return t1;
  }else{
    t1.create3(f(t.rootTree()), map(f, t.leftTree()), map(f, t.rightTree()));
  }
}