import Data.List
mergeAndSortDigits :: Int -> Int -> Int
mergeAndSortDigits x y = listToNumber $ sortDigits (mergeDigits x y) x y
--mergeAndSortDigits x y = listToNumber (sortDigits nub $ (numberToList x++numberToList y) sum numberToList x sum numberToList y)

mergeDigits :: Int -> Int -> [Int]
mergeDigits x y = nub (numberToList x ++ numberToList y)

numberToList :: Int -> [Int]
numberToList n
  | n == 0 = []
  | otherwise = numberToList(n `div` 10)++[n `rem` 10]

listToNumber :: [Int] -> Int
listToNumber [] = 0
listToNumber (x:xs) = x*(10^length xs) + listToNumber xs 

sortDigits :: [Int] -> Int -> Int -> [Int]
sortDigits [] _ _ = []
sortDigits list1 x y
  | (sum (numberToList x)) <= (sum (numberToList y)) = sort list1
  | otherwise = reverse $ sort list1
