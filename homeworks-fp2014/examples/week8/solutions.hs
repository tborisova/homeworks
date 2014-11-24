abs' x = if x >= 0
            then  x
            else -x

absGuards x
  | x > 0 = x
  | x == 0 = 0
  | otherwise = -x

fib n
  | n == 0 = 1
  | n == 1 = 1
  | otherwise = fib(n-1) + fib(n-2)

sumDigits x = if x == 0
                      then 0
                      else rem x 10 + sumDigits(div x 10)

product' a b c = a*b*c

isPrime n
  | n == 0 = False
  | n == 1 = False
  | n == (sumDivisors n 2) = True
  | otherwise = False

sumDivisors n current
  | n == 0 = 0
  | n == current = current
  | rem n current == 1 = sumDivisors n (current + 1)
  | rem n current == 0 = current + sumDivisors n  (current + 1)


--length'::[elements]->Int
length'::(Eq a) =>[a]->Int  
length' elements
  | elements == [] = 0
  | otherwise = 1 + length' (tail elements)

-- това е patter matching - различно е от pipes
--length'::[a]->Int
--length' [] = 0
--length' (x:xs) = 1 + length' xs

reverse'::[elements]->[elements]
reverse' [] = []
reverse' (x:xs) = (reverse' xs)++[x]

minlist::(Ord a) => [a]->a
minlist elements
  | length' elements == 1 = head elements
  | otherwise = (min (head elements) (minlist (tail elements)))

-- pattern matching
-- minlist [x] = x
-- minlist (x:xs) = min x (minlist xs)

take'::[a]->Int->[a]
take' [] _  = []
take' elements 0 = []
take' elements pos = [head elements]++(take' (tail elements) (pos - 1))

takeWhile'::[a]->(a->Bool)->[a]
takeWhile' [] _ = []
takeWhile' (x:xs) pred
  | pred x = x:(takeWhile' xs pred)
  | otherwise = []


-- [1,2,3]!! 2->3
---- x:xs  едната част на списъка - head, а xs са останалите елементи
-- 1:[2, 3] => [1, 2,3]
-- head [1, 2, 3,4] -> 1
-- tail [1, 2, 3, 4] -> 4
----- -- ++ [1,2,3]++[4,5,6]  [1,2,3,4,5,6]
-- (((product' 3) 6) 2) - currying - partial application
-- :type product'