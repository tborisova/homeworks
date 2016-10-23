n(0).
n(X) :- n(Y), X is Y + 1.

divices(X, Y) :- 0 is Y mod X.

notPrime(X) :- Last is X-1, between(2, Last, D), divices(D, X).
prime(X) :- not(notPrime(X)).
p(N, X) :- Last is N-1, between(2, Last, X), divices(X, N), prime(X).
q(N, Res) :- bagof(X, p(N, X), Res).


countFives([], 0).
countFives([X|Tail], Res) :- X = 5, countFives(Tail, SubRes), Res is SubRes + 1, !.
countFives([X|Tail], Res) :- X =\= 5, countFives(Tail, Res), !.

list_has_two_fives(List) :- countFives(List, Res), Res is 2.

fives([]).
fives([H|_]) :- list_has_two_fives(H), !.
fives([_|T]) :- fives(T).


%common_elements_in_lists(L, L1, L3)  :- bagof(X, (member(X, L), member(X, L1)), L3).
common_elements_in_lists([], _, []).
common_elements_in_lists([X|T1], L2, SubRes) :- member(X, L2), 
											 	common_elements_in_lists(T1, L2, SubRes), 
											 	member(X, SubRes).


common_elements_in_lists([X|T1], L2, [X|SubRes]) :- member(X, L2), 
											 	common_elements_in_lists(T1, L2, SubRes), 
											 	not(member(X, SubRes)).

common_elements_in_lists([X|T1], L2, Res) :- not(member(X, L2)), common_elements_in_lists(T1, L2, Res).

leng([], 0).
leng([_|T], Res) :- leng(T, Subres), Res is Subres + 1.

threeRule(List) :- member(X, List), member(Y, List), X \= Y, common_elements_in_lists(X, Y, L), leng(L, Result), Result < 3, !.

notThree(List) :- not(threeRule(List)).

