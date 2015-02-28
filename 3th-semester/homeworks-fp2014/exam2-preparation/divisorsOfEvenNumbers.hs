divisorsOfEvenNumbers :: Integer -> [[Integer]]
divisorsOfEvenNumbers n = [list_of_divisors x | x <- [n..], even x]

list_of_divisors :: Integer -> [Integer]
list_of_divisors n = [x | x <- [1..n], n `rem` x == 0]