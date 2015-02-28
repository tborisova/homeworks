divisorsOfOddNumbers :: Integer -> [[Integer]]
divisorsOfOddNumbers 0 = []
divisorsOfOddNumbers n = [divisors x | x <- [n..], odd x]

divisors :: Integer -> [Integer]
divisors n = [ x | x <- [1..n], n `rem` x == 0]