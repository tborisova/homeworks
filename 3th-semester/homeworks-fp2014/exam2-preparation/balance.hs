balance :: Int -> [Int] -> Int
balance _ [] = 0
balance n (x:xs)
  | sum (x:xs) > n = removeAtLeast (sum (x:xs) - n) (x:xs)
  | otherwise = 0

removeAtLeast :: Int -> [Int] -> Int
removeAtLeast _ [] = 0
removeAtLeast diff (x:xs)
  | diff == x = 1
  | otherwise = 1+(removeAtLeast (diff - x) xs)