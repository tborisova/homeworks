byCar(auckland,hamilton). 
byCar(hamilton,raglan). 
byCar(valmont,saarbruecken). 
byCar(valmont,metz). 
 
byTrain(metz,frankfurt). 
byTrain(saarbruecken,frankfurt). 
byTrain(metz,paris). 
byTrain(saarbruecken,paris). 
 
byPlane(frankfurt,bangkok). 
byPlane(frankfurt,singapore). 
byPlane(paris,losAngeles). 
byPlane(bangkok,auckland). 
byPlane(singapore,auckland). 
byPlane(losAngeles,auckland).

  %% Base cases
travel(X,Y, go(byCar(X,Y))) :- byCar(X,Y).
travel(X,Y, go(byTrain(X,Y))) :- byTrain(X,Y).
travel(X,Y, go(byPlane(X,Y))) :- byPlane(X,Y).

%% Inductive cases
travel(X,Y, go(byCar(X,Z),G)) :-
  byCar(X,Z),
  travel(Z,Y,G).

travel(X,Y, go(byTrain(X,Z),G)) :-
  byTrain(X,Z),
  travel(Z,Y,G).

travel(X,Y, go(byPlane(X,Z),G)) :-
  byPlane(X,Z),
  travel(Z,Y,G).