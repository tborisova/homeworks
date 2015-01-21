data BTree = Empty | BTree Int BTree BTree

levelMax :: BTree -> Int -> Int
levelMax Empty _ = 0
levelMax (BTree root left right) k
  | k == 0 = root 
  | otherwise  = max (levelMax left (level - 1)) (levelMax right (level - 1))