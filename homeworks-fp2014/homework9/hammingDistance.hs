hammingDistance :: String -> String -> Int
hammingDistance str1 "" = length str1
hammingDistance "" str2 = length str2
hammingDistance str1 str2 = sum [ 1 | (x,y) <- zip str1 str2, x /= y ]