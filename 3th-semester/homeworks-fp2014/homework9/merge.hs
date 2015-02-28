merge :: [a] -> [a] -> [a]
merge [] l2 = l2
merge l1 [] = l1
merge l1 l2 = concat [[x,y] | (x,y) <- zip l1 l2]

