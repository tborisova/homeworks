% D is delitel na N
delitel(N, D) :- 0 is N mod D.

between(A, B, A) :- A =< B.
between(S, E, X) :- S < E, Y is S + 1, between(Y, E, X).

notPrime(X) :- K is X - 1, between(2, K, Num), delitel(X, Num). 
prime(X) :- not(notPrime(X)).

p(F, D) :- Last is F - 1, between(2, Last, D), delitel(F, D), prime(D).

minP(F,D) :- p(F, D), not(p(F, Q), Q < D).

member(X, [X|_]).
member(X, [_|T]) :- member(X, T).

q(N, Res) :- p(N, K), not(member(K, Res)), q(N, [K|Res]). 
%q(N, Res) :- p(N, K), q(N, Res). 
