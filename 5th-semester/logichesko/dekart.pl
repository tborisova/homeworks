dekart([],[]).
dekart([[A], [B], [C], [D]],[A, B, C, D]).
dekart([A1, A2, A3, A4], R) :- dekart(Y, R), Y is [A1, A2, A3, A4].