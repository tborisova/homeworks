accRev([H|T],A,R):-  accRev(T,[H|A],R). 
accRev([],A,A).
rev(L,R):-  accRev(L,[],R).

appendM([],L,L). 
appendM([H|T],L2,[H|L3])  :-  appendM(T,L2,L3).

accLen([_|T],A,L)  :-    Anew  is  A+1,  accLen(T,Anew,L). 
accLen([],A,A).
leng(List,Length)  :-  accLen(List,0,Length).


accP([],[],A,A).
accP([],[Ha|Ta],A,Res) :- leng([Ha|Ta], LA), Anew is A+(Ha*10^(LA-1)), accP([], Ta, Anew, Res).  
accP([Ha|Ta],[],A,Res) :- leng([Ha|Ta], LA), Anew is A+(Ha*10^(LA-1)), accP([], Ta, Anew, Res).  

accP([Ha|Ta], [Hb|Tb], A, Res) :- leng([Ha|Ta],LA), leng([Hb|Tb],LB), Anew is A+(Ha*10^(LA-1))+(Hb*10^(LB-1)), accP(Ta, Tb, Anew, Res).

p(L1, L2, Res) :- accP(L1, L2, 0, Res).

accSum([H|T], A, L) :- Anew is H+A, accSum(T, Anew, L).
accSum([],A, A).
sum(List, Length) :- accSum(List, 0, Length).

encodeAcc([], []).
encodeAcc([Z, O], [[Z, O]]) :- Z is 0, O is 1.
encodeAcc([H|Ta], [[H]|Tb]) :-  encodeAcc(Ta, Tb).
%encodeAcc([H|Ta], [Hb|Tb]) :-  H is 1, append(Hb, [H], newRes), encodeAcc(Ta, [newRes|Tb]).
encode([_|Ta], Res) :- rev(Ta, [_|Tb]), rev(Tb, R), encodeAcc(R, newRes), appendM([0], newRes, Res).


n(0).
n(X) :- n(Y), X is Y+1.
%in_square(X1, Y1, A, X, Y) :- n(X), n(Y), Y < Y1, X < Y1, X < X1+A, Y<Y1+A.
%p(X1, Y1, A, X2, Y2, R, X, Y) :- in_square(X1, Y1, A, X, Y), in_okrujnost(X2, Y2, R, X, Y).


%X1,Y1

%X1+A = X3 - ednata strana, Y1+A = Y3- drugata
%(X1, Y1), (X1+A, Y1), (X1, Y1+A), (X1+A, Y1+A) - kvadrat

%X2, Y2 - centur
%R - raduis
%Xt, Yt

%ако Xt + 

memberF(Y, [[_, Y]]).
memberF(Y, [[_, X]|T]) :- X is Y; memberF(Y,T).
i([[_,Y]|T]) :- not(memberF(Y,T)).

smaller(_, _, []).
smaller(X, Y, [[X2, Y2]|T]) :- X < X2, Y < Y2, smaller(X2, Y2, T).
bigger(_, _, []).
bigger(X, Y, [[X2, Y2]|T]) :- X > X2, Y > Y2, bigger(X2, Y2, T).
monotonna([[_, _]]).
monotonna([[X, Y]|T]) :- smaller(X, Y, T); bigger(X, Y, T).

findXfromY(Y, [[X, Y]], X).
findXfromY(Y, [[X, Y]|_], X).
findXfromY(Y, [[_, _]|T], X) :- findXfromY(Y,T,X).

findYfromX(X, [[X, Y]], Y).
findYfromX(X, [[X, Y]|_], Y).
findYfromX(X, [[_, _]|T], Y) :- findYfromX(X,T,Y).

%compositionAcc([], _, A, A).
%compositionAcc([[_, Y1]|T1], L2, _, _) :- findXfromY(Y1, L2, X3),append([x,3],[], res) compositionAcc(T1, L2, [[X3, Y1]|_], [[X3, Y1|_]]).
%composition(L1, L2, Res) :- compositionAcc(L1, L2, [], Res).
%composition([[_, Y1]], [[Y1, X3]], [[X3, Y1]]).

composition([], _, []).
composition([[X1, Y1]|T1], L2, [[X1, Y3]|SubRes]) :- findYfromX(Y1, L2, Y3), composition(T1, L2, SubRes). %, [], Res).

% [[1,2], [3,4]], [[2,5], [4,6]], Res = [1,5], [3,6]

flatten2([], []) :- !.
flatten2([L|Ls], FlatL) :-
    !,
    flatten2(L, NewL),
    flatten2(Ls, NewLs),
    append(NewL, NewLs, FlatL).
flatten2(L, [L]).


%p([[1,2,3,4], [5,6,1,2,3], [4,1,2,3,5,6]], M), тогава M = 1,2,3,4























