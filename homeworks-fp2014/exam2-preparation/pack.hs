pack :: [Int] -> [(Int,Int)]
pack [] = []
pack list = [(num, occurences) | num <- list, occurences <- (remove_duplicates list num)]

remove_duplicates :: [Int] -> [Int]