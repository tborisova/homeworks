twice([], []).

twice([ H | Ta ], [H, H | Tb]) :- twice(Ta, Tb).