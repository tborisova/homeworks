%prosto(X, Y).

%prosto(X, Y) :- 

delitel(2, 1).
delitel(2, 2).
delitel(X, Y) :- X >= Y, 0 is X rem Y, R is Y + 1, delitel(X, R).

getDivisors(X) :- delitel(X, 2).
