countEliminations :: [Int] -> Int
countEliminations [] = 0
countEliminations [x,y,z]
	| y == maximum [x,y,z] && (x == y) = 1
	| y == maximum [x,y,z] && (y == z) = 1
	| otherwise = 0
countEliminations (x:y:z:xs)
	| y == maximum (x:y:z:xs) && (x == y) = 1 + (countEliminations (z:xs))
	| y == maximum (x:y:z:xs) && (y == z) = 1 + (countEliminations (x:xs))
	| otherwise = 0

--countEliminations :: [Int] -> Int
--countEliminations [] = 0
--countEliminations list
--	| eliminationIsPossible list (maximum list) = 1 + (countEliminations $ eliminate list (eliminationIsPossible list (maximum list)))
--	| otherwise = 0

--eliminationIsPossible :: [Int] -> Int -> [Int]
--eliminationIsPossible [] _ = []
--eliminationIsPossible list max_el
--	| max_el == elemAt ((indexOf list max_el) + 1) list = [indexOf list max_el, (indexOf list max_el) + 1]
--	| max_el == elemAt ((indexOf list max_el) - 1) list = [indexOf list max_el, (indexOf list max_el) - 1]

--elemAt :: [Int] -> Int -> Int
--elemAt [] _ = error "empty list"
--elemAt (x:xs) index
--	| index == 0 = x
--	| otherwise = (elemAt xs (index-1))

--indexOf :: [Int] -> Int -> Int
--indexOf [] _ = error "empty list"
--indexOf (x:xs) element = indexOfHelper (x:xs) element 0

--indexOfHelper :: [Int] -> Int -> Int -> Int
--indexOfHelper (x:xs) element start
--	| x == element = start
--	| otherwise = indexOfHelper xs element (start+1)

--eliminate :: [Int] -> [Int] -> [Int]
--eliminate list indices_of_eliminations
--	| 
