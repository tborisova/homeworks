r - l < 1 - condition
r = m + 1
l = m - 1


int* p = lower_bound(a, a + n, x);
p - a = index of element

тръби

k.l <= sum ai
l - length

0 <= l <= sumai/k
sum ai/len >= k => може да се отреже

трябва да се търси от len до r

двоично търсене по отговора

isPosibble(int len) - дали е възможно

while(l+1 < r){
  m = ..
  if(isPossible(m)){

    look in [m, r];
  }else{
    look in [l, m - 1];
  }
} 


suma
алкохолици

сума:

първи начин:
сортираме + binary search

втори начин:
i = 0 j = n - 1

ai + aj < si i++

ai + aj > si j--

от статията 



http://judge.openfmi.net:9280/practice/get_problem_description?contest_id=36&problem_id=104

[l, r]
за m пишем функция дали е възможно да бъде това разстояние
разстояние между всеки два студента ще е тази функция


http://judge.openfmi.net:9280/practice/get_problem_description?contest_id=4&problem_id=13
pair(string, int)
aleksander 10
atanas 11 -- ot 11 do 11
eleonora 15 -- ot 12 do 15

elliot

4 3 3
3 4 0 5 
5
9
100

3 4 0  -> 7 >= 5| 4 0 5 -> 9 

=== > 0

9 >= 9 ====> 1

100 -> -1