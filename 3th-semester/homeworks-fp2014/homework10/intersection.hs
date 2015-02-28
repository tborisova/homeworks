intersection :: (Eq a) => [a] -> [a] -> [a]
intersection [] list2 = []
intersection list1 [] = []
intersection list1 list2 = [x | x <- list1, elem x list2]