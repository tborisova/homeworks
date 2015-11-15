directlyin(natasha, irina).
directlyin(olga, natasha).
directlyin(katarina, olga).
in(X, Y) :- directlyin(X, Y).
in(X,Y) :-
  directlyin(X,Z),
  in(Z,Y).