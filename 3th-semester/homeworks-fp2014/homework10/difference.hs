difference :: (Eq a) => [a] -> [a] -> [a]
difference [] list = []
difference list [] = list
difference list1 list2 = [x | x <- list1, notElem x list2]