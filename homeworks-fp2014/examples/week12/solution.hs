import Data.Char

ones::[Int]
ones = [1,1..]

naturals::[Int]
naturals = [1..]

evens::[Int]
evens = [x | x <- [1..], even x]

fib::[Int]
fib = fib' 1 1

fib'::Int -> Int -> [Int]
fib' a b = a:(fib' b (a+b))

isPrime::Int -> Bool
isPrime x = sum [ 1 | y <- [1..x-1], x `rem` y == 0] == 1

primes::[Int]
primes = [x | x <- [1..], isPrime x] 

combineStreams::(a->a->a) -> [a] -> [a] -> [a]
combineStreams func [] l2 = []
combineStreams func l1 [] = []
combineStreams func l1 l2 = zipWith func l1 l2 -- the same as [func x y | (x,y) <- zip l1 l2]

generateStream :: (Enum a) => (a->a)->a->a->[a]
generateStream func start end = [x | x <- [start,func(start)..end]]++generateStream func start end

integers :: Int -> Int -> [Int]
integers start end = [x | x <- [start..end]]++integers start end

nextLetter :: Char -> Char
nextLetter letter = chr (ord letter + 1)

letters :: [Char]
letters = [x | x <- ['a'..'z']]++letters

listToStream :: [a] -> [a]
listToStream [] = []
listToStream l1 = l1++listToStream l1

timesMet :: (Ord a) => [a] -> a -> Int
timesMet [] _ = 0
timesMet (x:xs) num
  | num == x = 1 + timesMet xs num
  | otherwise = timesMet xs num

duplicatePrimes' :: Int -> [Int]
duplicatePrimes' num
  | isPrime num = [num,num]++duplicatePrimes' (num + 1)
  | otherwise = [num]++duplicatePrimes'(num + 1)

duplicatePrimes :: [Int]
duplicatePrimes = duplicatePrimes' 1

fact :: Int -> Int
fact n
  | n == 0 = 1
  | otherwise = n*fact(n-1)

taylorSeries :: Integer -> [Float]
taylorSeries x = [fromIntegral(x^n) / fromIntegral(fact n) | n <- [0..] ]

type Board = [[String]]
type Player = String
