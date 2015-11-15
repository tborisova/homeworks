second(X, [_,X|_]).

swap12(L1,L2) :- L1 = [L1a,L1b|_], L2 = [L1b,L1a|_].