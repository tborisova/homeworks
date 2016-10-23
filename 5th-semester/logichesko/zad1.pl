member(X, [X|_]).
member(X, [_|T]) :- member(X, T).
p1(X, [[X]]).
p1(X, [H|T]) :- member(Y, X), member(Y, H); p1(X, T).
p2(X, [[X]]).
p2(X, [H|T]) :- member(Y, X), member(Y, H), p1(X, T).
p3(X, [[X]]).
p3(X, [H|T]) :- member(Y, X), member(Y, H); p2(Y, T), p3(X, T).

