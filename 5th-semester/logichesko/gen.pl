gen(X) :- gen2(X, 1).
gen2([], 0).
gen2([1], 1).
gen2([1,2,3],2).
gen2([H|T], N):- gen2([])