member(X, [X|_]).
member(X, [_|T]) :- member(X, T). 

append([], L, L).
append([H|T], L, [H|Z]) :- append(T, L, Z).

reverse([], []).
reverse([H|T], L) :- reverse(T, L1), append(L1, [H], L).

% sublist(X,Y):- append(L1,L2,Y), append(X,L3,L2).
 
between(A, B, A) :- A =< B.
between(A, B, X) :- A < B, A1 is A + 1, between(A1, B, X).

range(B1, B, []) :- B1 > B.
range(A, B, [A | Res]) :- A =< B, A1 is A + 1, range(A1, B, Res).

numbers(Count, List) :-
    findall(N, between(1,Count,N), List).

list_length([]     , 0 ).
list_length([_|Xs] , L ) :- list_length(Xs,N) , L is N+1 .

correct(X, N) :- list_length(X, L), N is L, N > 0.

nat(0).
nat(X) :- nat(M), X is M + 2.

%[1,2], [1,2,3,4], [1,2,3,4,5,6]

element_at(X,[X|_],1).
element_at(X,[_|L],K) :- element_at(X,L,K1), K is K1 + 1.

last(X, [X]).
last(X, [_|T]):- last(X, T).
has_item(X, [X|T]).
has_item(X, [H|T]) :- has_item(X, T).

gen2(2, [1,2]).
gen2(N, X) :- N is M + 2, R is M + 1, gen2(M, L), append(L,[R, N],X). %correct(X, N). 
gen(X) :- gen2(2, X).

p([L1, L2, L3], X) :- member(X, L1), member(X, L2), not(member(X, L3)).
p([L1, L2, L3| T], X) :- member(X, L1), p([L2, L3 | T], X).
p(L) :- p(L, X).


majoriraLM(L, M, X) :- member(X, L), not(member(X, M)).
majorira([L1, L2 | T], M) :- member(X, L1), majoriraLM(L1, L2, X),majorira([L2|T], M), append(L1, [], M). 


delitel(M, N) :- 0 is M rem N.
%deliteli(N, X) :- delitel(N, Y), append([Y])

%prosto(1).
%prosto(2).
%prosto(N) :- deliteli(N, [1, N]). %, X is N; X is 1.
%prostdelitel(M, N) :- delitel(M, N), prosto(N).
%prosti(X, Y) :- prostdelitel(X, Z), prostdelitel(Y, Z).