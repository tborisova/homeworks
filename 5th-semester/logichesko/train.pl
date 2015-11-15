directTrain(saarbruecken,dudweiler). 
directTrain(forbach,saarbruecken). 
directTrain(freyming,forbach). 
directTrain(stAvold,freyming). 
directTrain(fahlquemont,stAvold). 
directTrain(metz,fahlquemont). 
directTrain(nancy,metz).

travelFromTo(From,To) :- directTrain(From, To).
travelFromTo(From, To) :- directTrain(From, Stop), travelFromTo(Stop, To).