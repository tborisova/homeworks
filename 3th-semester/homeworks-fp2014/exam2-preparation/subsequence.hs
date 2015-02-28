import Data.List

subsequence :: (Eq a) => [a] -> [a] -> Bool
subsequence [] [] = True
subsequence [] l2 = True
subsequence l1 [] = False
subsequence  (x:xs) list2 = (elem x list2) && subsequence xs (dropWhile (/= x) list2)
