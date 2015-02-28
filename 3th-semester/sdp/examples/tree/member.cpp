template <typename T> bool member(const T& a, const tree<T>& t){
  if(t.empty()) return 0;
  if(a == t.rootTree()) return true;
  return member(a, t.leftTree()) || member(a, t.rightTree());
}