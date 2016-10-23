% Празният списък е елемент

empty([]).
p1([H|T]) :- (H = []); p1(T).

mymember(H, [H|_]).
mymember(H, [_|T]) :- mymember(H, T).

begin([], _).
begin([H|Q], [H|L]) :- begin(Q, L).

sublist(L, M) :- begin(L, M).
sublist(L, [_|M]) :- sublist(L, M). 

subset([], _).
subset([H|T], L) :- mymember(H, L), subset(T, L).

twoListsHaveCommonEl([X|_], [X|_]).
twoListsHaveCommonEl([X|T], L) :- mymember(X, L); twoListsHaveCommonEl(T, L).

p2(L) :- mymember(Y, L), mymember(X, L), (X \= Y), not(twoListsHaveCommonEl(Y,X)).

p3(L) :- not(p2(L)).

%commonEl(L) :- mymember(Y, L), mymember(X, L), (subset(X, Y); subset(Y, X)).
%p2(L) :- mymember(Y, L), mymember(X, L), not(subset(X, Y)). 

n(0).
n(X) :- n(Y), X is Y + 1.
gen(N, M, K) :- n(N), n(M), n(K), K*K =:= N*N + M*M. 
%p(X, N, M, K) :- gen(N, M, K), S is N + M + K, someLastEl(X, Last), S < Last,
%				not(someSecondEl(X, N), not(someSecondEl(X,M), somesumEl(X, K).

pythag2(X,Y,Z,N) :-
   length(_, N),
   between(1,N,X),
   between(1,N,Y),
   between(1,N,Z),
   Z*Z =:= X*X + Y*Y.