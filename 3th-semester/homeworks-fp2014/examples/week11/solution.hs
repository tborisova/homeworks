-- [x | x <- [1..], x > 5] - all > 5
-- [1, 3..11] - стъпка 2
-- [11, 9..1] - стъпка -2


import Data.List

squares::Int->Int->[Int]
squares a b = [x^2 | x <- [a..b]]

sumSquares :: Int -> Int -> Int
sumSquares a b = foldl (+) 0 $ squares a b

productEvenCubes::Int -> Int -> Int
productEvenCubes a b = foldl (*) 1 [x^3  | x <- [a..b], even x]

factors::Int -> [Int]
factors a = [x | x <- [1..a-1], rem a x == 0]

isPrime :: Int -> Bool
isPrime a = factors a == [a]

concat' :: [[a]] -> [a]
concat' list_of_lists = [x | y <- list_of_lists, x <- y]

tuples :: Int -> Int -> [(Int, Int)]
tuples a b = [(x, y) | x <- [a..b], y <- [x..b] ]

isCorrect::Int -> Int -> Int -> Bool
isCorrect x y z = x^2 + y^2 == z^2 && x+y>z && x+z > y && z+y > x

pythagoreanTriples::Int ->  [(Int, Int, Int)]
pythagoreanTriples a = [(x, y, z) | x <- [1..a], y <- [1..a], z <- [1..a], isCorrect x y z || isCorrect y z x || isCorrect z x y]

isPefect::Int -> Bool
isPefect num = num == (foldl (+) 0 $ factors num)

perfects :: Int -> [Int]
perfects a = [x | x <- [1..a], isPefect x]

scalarProduct :: [Int] -> [Int] -> Int
scalarProduct v1 v2 = foldl (+) 0 [x*y | (x,y) <- zip v1 v2]

replicate' :: Int -> a -> [a]
replicate' num el = [el | _ <- [1..num] ]

qsort :: (Ord a) => [a] -> [a]
qsort [] = []
qsort (x:xs) = (qsort [y | y <- xs, y < x])++[x]++(qsort [z | z <- xs, z >= x])

tupleSort :: (Ord a) => [(a, b)] -> [(a, b)]
tupleSort [] = []
tupleSort (x:xs) = (tupleSort [y | y <- xs, fst y < fst x])++[x]++(tupleSort [z | z <- xs, fst z >= fst x])

timesMet :: (Ord a) => [a] -> a -> Int
timesMet [] _ = 0
timesMet (x:xs) num
  | num == x = 1 + timesMet xs num
  | otherwise = timesMet xs num

occurrences :: (Ord a) => [a] -> [(a, Int)]
occurrences [] = []
occurrences (x:xs) = [(x, timesMet xs x + 1)]++(occurrences(nubBy (\y z -> y == x) xs))

-- правиш уникален и обхождаш елементите на другия
