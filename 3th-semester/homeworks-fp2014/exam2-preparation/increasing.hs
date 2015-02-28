increasing::(Int -> Int) -> Int -> Int -> Bool
increasing f 0 0 = False
increasing f start end = [x | x <- [start..end-1], f x >= f (x+1) ] == []