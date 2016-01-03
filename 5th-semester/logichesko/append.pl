append([],[],[]).
append(A, [], A).
append([], B, B).
append([X|XS], Y, [X|R]) :- append(XS, Y, R).
last(X,L) :- append(_, [X], L).
first(X, L) :- append([X],[], L).
perm([],[]).
perm([X|XS], Res) :- perm(XS, T), insert(X, T, Res).