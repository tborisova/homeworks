rev2([], Buf, Buf).
rev2([X|XS], Buf, Res) :- rev2(XS, [X|Buf], Res).
reverse(X, Y) :- rev2(X, [], Y).