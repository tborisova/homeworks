word(astante,  a,s,t,a,n,t,e). 
word(astoria,  a,s,t,o,r,i,a). 
word(baratto,  b,a,r,a,t,t,o). 
word(cobalto,  c,o,b,a,l,t,o). 
word(pistola,  p,i,s,t,o,l,a). 
word(statale,  s,t,a,t,a,l,e).

crossword(V1, V2, V3, H1, H2, H3) :- word(V1, _, X, _, Y, _, Z, _),
									word(V2, _, T, _, H, _, A, _),
									word(V3, _, F, _, G, _, J, _),
									word(H1, _, X, _, T, _, F, _),
									word(H2, _, Y, _, H, _, G, _),
									word(H3, _, Z, _, A, _, J,_).
