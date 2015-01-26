smallDigits :: Int -> (Int -> Int)
smallDigits n = (\k -> (sumAll k n))

sumAll :: Int -> Int -> Int
sumAll k n = sum [(smallestDivisitor y k) | y <- [1..n]]

smallestDivisitor :: Int -> Int -> Int
smallestDivisitor number k 
	| [num | num <- (divisoursOfNum number), all (\x -> x <= k) (listOfDigits num)] == [] = 0
	| otherwise = head [num | num <- (divisoursOfNum number), all (\x -> x <= k) (listOfDigits num)]

divisoursOfNum :: Int -> [Int]
divisoursOfNum 0 = []
divisoursOfNum n = [x | x <- [2..n], n `rem` x == 0]

listOfDigits :: Int -> [Int]
listOfDigits n
	| n >= 0 && n <= 9 = [n]
	| otherwise = (listOfDigits $ n `div` 10)++[(n `rem` 10)]