import Data.Char

compress :: String -> Int -> String
compress [x] number 
    | number == 0 = [x]
    | otherwise = (number_to_string(number+1))++[x]
compress (x:y:xs) number
    | x == y = compress (y:xs) (number + 1)
    | number == 0 = x:(compress (y:xs) 0)
    | otherwise = number_to_string(number+1)++[x]++(compress (y:xs) 0)

number_to_string :: Int -> [Char]
number_to_string x
  | x >= 0 && x <= 9 = [chr(ord '0' + x)]
  | otherwise = chr(ord '0' + (div x 10)):number_to_string(rem x 10)


lengthEncode :: String -> String
lengthEncode "" = ""
lengthEncode str = compress str 0