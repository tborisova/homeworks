sub([], []).
sub([_, XS], Res) :- sub(XS, Res).
sub([X|XS], [X | Res]) :- sub(XS, Res).