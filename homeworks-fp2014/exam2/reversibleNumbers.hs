reversibleNumbers :: Int -> [Int]
reversibleNumbers n = [x | x <- [1..n], isReversible x]

isReversible :: Int -> Bool
isReversible n
	| n `rem` 10 == 0 = False
	| otherwise = onlyOdds(n + reverseNumber n)

reverseNumber :: Int -> Int
reverseNumber 0 = 0
reverseNumber n = (n `rem` 10)*(10^((digitsCount n) - 1)) + (reverseNumber(n `div` 10))

digitsCount :: Int -> Int
digitsCount n
	| n == 0 = 0
	| otherwise = 1+digitsCount(n `div` 10)

onlyOdds :: Int -> Bool
onlyOdds n
	| n == 0 = True
	| otherwise = (odd $ n `rem` 10) && (onlyOdds $ n `div` 10)

