member(X, [X|_]).
member(X, [_|XS]) :- member(X, XS).

# p(L) :- Y;	 Y is member(X, L).

Задача 2. Казваме, че списък X мажорира списък Y , ако

всички елементи на X са елементи на Y . Да се дефинира

на пролог предикат p(L, M), който по даден списък от спи-

съци L намира списък M, който съдържа всички елементи

на L и в който никой елемент не се мажорира от елемент,

намиращ се след него в списъка.

Зад. 1. За произволен списък [a1, a2, . . . , ak] ще казваме, че

списъците от вида [am, am+1, . . . , am+i], където 1 5 m 5 k и

0 5 m 5 k − m, са негови подспицъци. Да се дефинира пре-

дикат p(X, Y, Z), който по дадени списъци X и Y генерира

всички подсписъци Z на Y , такива че дължината на Z е

колкото дължината на X, всеки елемент на Z е по-голям от

елемента, намиращ се на същата позиция в X и последните

елементи на Z и Y са равни.