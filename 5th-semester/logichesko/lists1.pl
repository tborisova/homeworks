second(X, [_,X|_]).

swap12(L1,L2) :- L1 = [L1a,L1b|_], L2 = [L1b,L1a|_].

addone([],[]).
addone([H|T], [Y|T2]) :- Y is H + 1, addone(T, T2).


scalarmult(Alpha, [], []).
scalarmult(Alpha, [H1|T1], [H2|T2]) :-
  H2 is H1*Alpha,
  scalarmult(Alpha, T1, T2).

adot([],[],A,A).
adot([H1 | T1], [H2 | T2], Acc, Result) :- Anew is (A + H1*H2), adot(T1, T2, Anew, Result).
dot(H, J, Result) :- adot(H, J, 0, Result). 