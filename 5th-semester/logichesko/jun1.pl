mymember(X, [X|_]).
mymember(X, [_|XS]) :- mymember(X, XS).

p([N], N).
p(L,N) :- mymember(X,L), N is X*X.
p(L,N) :- mymember(X,L), mymember(Y,L), X=\=Y, J is X*Y, N > J, N1 is N/J, p(L, N1).


n(0).
n(X) :- n(Y), X is Y+1.
%circles(X, Y, R, X, Y, S) :- n(N), S is R+N.
circles(X, Y, R, X, T, S) :- n(N), T is Y+N, S is R+N,circles(X, Y, R, X, T, S).
circles(X, Y, R, Z, Y, S) :- n(N), Z is X+N, S is R+N,circles(X, Y, R, Z, Y, S).
circles(X, Y, R, Z, T, S) :- n(N), Z is X+N, T is Y+N,S is R+N,circles(X, Y, R, Z, T, S).

