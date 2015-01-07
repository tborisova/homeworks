--foldl'::(a->a)->a->[a]->a
--foldl' func res [] = res
--foldl' func res (x:xs) = foldl' func (func res x) xs
-- init list - elements without the last
-- las lst - last element
-- foldr' (:) [] [1..]
--foldr'::(a->a)->a->[a]->a
--foldr' func res [] = res
--foldr' func res (x:xs) = func x (foldr' func res xs)

-- list1 is sublist of list2
-- [1,2,3] [0.7,1,4,2,3] - true
-- [1,2,3] [0.7,3,4,2,1] - true
subsequence :: (Eq a) => [a] -> [a] -> Bool
subsequence [] list2 = True
subsequence list1 [] =  True
subsequence (x:xs) list2 = (elem x list2) && subsequence xs (dropWhile (/= x) list2)

increasing::(Int -> Int) -> Int -> Int -> Bool
increasing f 0 0 = False
increasing f start end = [x | x <- [start..end-1], f x >= f (x+1) ] == []

numberToList :: Int -> [Int]
numberToList num
  | num >= 0 && num <=9 = [num]
  | otherwise = numberToList(div num 10)++[rem num 10]

listToNumber :: [Int] -> Int
listToNumber [a] = a
listToNumber (x:xs) = x*(10^(length xs))+listToNumber(xs)

zeroInsertHelper :: [Int] -> [Int]
zeroInsertHelper [] = []
zeroInsertHelper [a] = [a]
zeroInsertHelper (x:y:xs) 
  | x == y = [x, 0]++zeroInsertHelper(y:xs)
  | rem (x+y) 10 == 0 = [x, 0]++zeroInsertHelper(y:xs)
  | otherwise = [x]++zeroInsertHelper(y:xs)

zeroInsert :: Int -> Int
zeroInsert 0 = 0
zeroInsert num = listToNumber(zeroInsertHelper(numberToList num))

isPrime::Int -> Bool
isPrime x = sum [ 1 | y <- [1..x-1], x `rem` y == 0] == 1

primesTill::Int -> [Int]
primesTill end = [x | x <- [1..end], isPrime x] 

primeFactorization :: Int -> [(Int, Int)]
primeFactorization 1 = [(1,1)]
primeFactorization num = [(prime_number, primeInNumber num prime_number) | prime_number <- primesTill num, (primeInNumber num prime_number) > 0]

primeInNumber :: Int -> Int -> Int
primeInNumber num prime_num
  | num `rem` prime_num == 0 = 1+primeInNumber (div num prime_num) prime_num
  | otherwise = 0

find :: (a->Bool) -> [a] -> a
find pred [] = error "Error!"
find pred (x:xs)
  | pred x = x
  | otherwise = find pred xs

replace :: Int -> [(Int, Int)] -> Int
replace num [] = num
replace num list = replaceHelper numberToList num list

replaceHelper :: [Int] -> [(Int, Int)] -> Int
replaceHelper number_list list_of_replace = [should_replace_number x list_of_replace | x <- number_list ]

should_replace_number :: Int -> [(Int, Int)] -> Int
should_replace_number num list
  | any (\x y -> x == num) list == 1 = y
  | otherwise = x
