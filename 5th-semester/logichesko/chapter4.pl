second(X, [_, X| _]).

swap12([X,Y|T], [Y,X|T]).

tran(eins,one). 
tran(zwei,two). 
tran(drei,three). 
tran(vier,four). 
tran(fuenf,five). 
tran(sechs,six). 
tran(sieben,seven). 
tran(acht,eight). 
tran(neun,nine).

listtran([],[]).
listtran([H|T],[H2|T2]) :- tran(H,H2), listtran(T, T2). 

twice([],[]).
twice([H|T], [H, H|X]) :- twice(T, X). 

combine1([],[],[]).
combine1([H|T], [H2|T2], [H, H2|T3]) :- combine1(T, T2, T3).

combine2([],[],[]).
combine2([H1|T1], [H2|T2], [[H1, H2]|T3]) :- combine2(T1, T2, T3).

combine3([],[],[]).
combine3([H1|T1], [H2|T2], [j(H1, H2)|T3]) :- combine3(T1, T2, T3). 
