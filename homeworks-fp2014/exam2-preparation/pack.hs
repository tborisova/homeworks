import Data.List

pack :: [Int] -> [(Int,Int)]
pack [] = []
pack list = nub [(num, occurences_in_list list num) | num <- list]

occurences_in_list :: [Int] -> Int -> Int
occurences_in_list [] _ = 0
occurences_in_list (x:xs) num
  | x == num = (occurences_in_list xs num) + 1
  | otherwise = occurences_in_list xs num