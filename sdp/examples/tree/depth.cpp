template <typename T> int depth(const tree<T>& t){
  if(t.empty()) return 0;

  int n,m;

  n = depth(t.leftTree());
  m = depth(t.rightTree());
  cout << "n " << n << "  m  " << m << endl;
  if(n > m) return n+1;
  return m + 1;
}