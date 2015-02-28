template <typename T>
queue<T> merge(queue<T> p, queue<T> q, const T& dummy){

  p.push(dummy);
  q.push(dummy);

  queue<T> r;
  T x,y;
  q.pop(y);
  p.pop(x);

  while(!q.empty() && !p.empty()){
    if(x < y){
      r.push(x);
      p.pop(x);
    } else{
      r.push(y);
      q.pop(y);
    }
  }

  if(!p.empty()){
    do{
      r.push(x);
      p.pop(x);
    } while(x != dummy);
  }else{
    do{
      r.push(y);
      q.pop(y);
    }while(y != dummy);
  }

  return r;
}