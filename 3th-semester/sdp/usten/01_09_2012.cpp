
template <typename T> ostream& stack<T>::operator<<(ostream& out, const stack<T>& st){
  T x;

  while(!st.empty()){
    st.pop(x);
    out << x << " ";
  }

  out << endl;
  return out;
}

template <typename T> istream& stack<T>::operator>>(istream& in, const stack<T>& st){
  T x;
 char ch = 'y';
  cout << "enter stack values, for end press n" << endl;

  while(ch != 'n'){
    cout << "enter stack element: ";
    in >> x;
    st.push(x);
    cout << "continue?(y/n) ";
    in >> ch;
  }
  return in;
}