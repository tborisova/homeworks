template <typename T> T accumulate(T (*op)(T,T), T null_value, const tree<T>& t){
  if(t.empty()){
    return null_value;
  }else{
    return op(op(accumulate(op, null_value, t.leftTree()), t.rootTree()), accumulate(op, null_value, t.rightTree()));
  }
}