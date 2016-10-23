empty([]).
empty([[]]).
empty([X|T]) :- empty(X), empty(T).
member([X|_], X).
member([_|T], X) :- member(T, X). 
lastEl([X], X).
lastEl([_|T], X) :- lastEl(T, X).
count([], 0).
count([_|T], C) :- count(T, CR), C is CR + 1.
gen(0).
gen(X) :- gen(XR), X is XR + 1.
positionIn([X], X, 0).
positionIn([_|T], X, POS) :- positionIn(T, X, POS1), POS is POS1 + 1.
append([], Y, Y).
append([A | X], Y, [A | Z]) :- append(X, Y, Z).
sublist(L, M) :- append(P, Q, M), append(L, R, Q).
p(X,Y,Z) :- sublist(Y,Z), lastEl(Y, K), lastEl(Z, J), K =:= J, count(Z, N), count(X, M), N =:= M, gen(N), member(Z, M1), member(X, M2), positionIn(Z, M1, POS1), positionIn(X, M2, POS2), POS1 > POS2. 