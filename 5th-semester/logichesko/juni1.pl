n(0).
n(X) :- n(Y), X is Y + 1.

accRev([H|T],A,R):-  accRev(T,[H|A],R). 
accRev([],A,A).
rev(L,R):-  accRev(L,[],R).

nextMember(X, D, Y) :- Y is X + D.

pAcc([X|Tail], D) :- nextMember(X, D, Y), pAcc([Y, X|Tail]).
p(L) :- n(X), n(D), pAcc([X|T], D), rev([X|T], L).