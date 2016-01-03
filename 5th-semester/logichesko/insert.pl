insert(X, [], [X]).
insert(X, L, R) :- append(L, [X], R).