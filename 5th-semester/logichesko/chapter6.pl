append([],L,L). 
append([H|T],L2,[H|L3])  :-  append(T,L2,L3).

prefix(P,L):-  append(P,_,L).
suffix(S,L):-  append(_,S,L).

sublist(SubL,L):- suffix(S,L),  prefix(SubL,S).

accRev([H|T],A,R):-  accRev(T,[H|A],R). 
accRev([],A,A).
rev(L,R):-  accRev(L,[],R).

leng([], 0).
leng([_|T], A) :- leng(T, S), A is S + 1. 
%lenAcc([_|T], A, Res) :- newA is A + 1, lenAcc(T, newA, Res).
%lenAcc([], A, A).
%leng(L, Res) :- lenAcc(L, 0, Res).

equal([], []).
equal([H1|T], [H1| T2]) :- equal(T, T2).

doubled(L) :- prefix(P, L), suffix(S, L), equal(P, S), leng(L, X), Y is X/2, leng(P, Y).

palindrome(L) :- rev(L, L).

toptail([], []).
toptail(InList, []) :- leng(InList, X), X =< 2. 
toptail(InList, OutList) :- leng(InList, X), X > 2, rev(InList, [_|T2]), rev(T2, [_|T3]), append(T3, [], OutList).

lastEl([H|T], X) :- rev([H|T], [X|_]).

swapfl([H|T], [H1|T1]) :- lastEl(T, H1), lastEl(T1, H), 
						  chopOffEnds([H|T], Outlist1),
						  chopOffEnds([H1|T1], Outlist2),
						  equal(Outlist1, Outlist2).

chopOffEnds([_|T],Outlist) :-
  rev(T, [_|RevOutlist]),
  rev(RevOutlist,Outlist).  

member(X, L) :- append(_,[X|_], L).


accSet([],L,L).
accSet([X|Inlist], AccList, Outlist) :-
  not(member(X,AccList)),
  accSet(Inlist,[X|AccList],Outlist).
accSet([X|Inlist], AccList, Outlist) :-
  member(X,AccList),
  accSet(Inlist,AccList,Outlist).
set(Inlist,Outlist) :-
  accSet(Inlist,[],RevOutlist),
  rev(RevOutlist, Outlist).
