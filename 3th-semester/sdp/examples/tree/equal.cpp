template <typename T> bool equal(tree<T>& t1, tree<T>& t2){
  if(t1.empty() && t2.empty()) return true;
  if(t1.empty() && !t2.empty() || !t1.empty() && t2.empty()) return false;
  return equal(t1.leftTree(), t2.leftTree()) && equal(t1.rightTree(), t2.rightTree());
}