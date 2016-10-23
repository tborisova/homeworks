increment(X, Y) :- Y is X + 1.
sum(X, Y, Z) :- Z is X + Y.

addone([],[]).
addone([H|T], [X|T3]) :- X is H + 1, addone(T, T3).
accMax([H|T],A,Max)  :- 
     H  >  A, 
     accMax(T,H,Max). 

accMax([H|T],A,Max)  :- 
     H  =<  A, 
     accMax(T,A,Max). 

accMin([],A,A).
accMin([H|T],A,Min)  :- H  <  A, accMin(T,H,Min). 
accMin([H|T],A,Min)  :-  H  >=  A, accMin(T,A,Min). 
min([H|T], X) :- accMin([H|T], H, X).

scalarMult(_,[],[]).
scalarMult(X,[H|T],[Y|T3]) :- Y is H*X, scalarMult(X, T, T3).

dotAcc([],[], А, А).
dotAcc([X|Ta],[Y|Tb], A, S) :- Anew is A + (X*Y), dotAcc(Ta, Tb, Anew, S).
dot(L1, L2, S) :- dotAcc(L1, L2, 0, S).