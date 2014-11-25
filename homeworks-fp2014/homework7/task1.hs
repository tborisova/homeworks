drop' :: Int -> [a] -> [a]
drop' _ [] = []
drop' 0 elements = elements
drop' n elements = (drop'(n - 1) (tail elements))
