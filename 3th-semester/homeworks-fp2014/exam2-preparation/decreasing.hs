decreasing :: (Int -> Int) -> Int -> Int -> Bool
decreasing f 0 0 = False
decreasing f start end = [x | x <- [start..end-1], f x <= f (x + 1) ] == []