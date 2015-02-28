data Tree a = Empty | Node a (Tree a) (Tree a)

levelSum :: Tree Int -> Int -> Int
levelSum Empty _ = 0
levelSum tree k = sum $ level k tree

level :: Int -> Tree Int -> [Int]
level _ Empty = []
level k (Node root left right)
  | k == 0 = [root]
  | otherwise = level (k-1) left++level (k-1) right

treeHeight :: Tree Int -> Int
treeHeight Empty = 0
treeHeight (Node root Empty Empty) = 1
treeHeight (Node root Empty right) = 1+(treeHeight right)
treeHeight (Node root left Empty) = 1+(treeHeight left)
treeHeight (Node root left right) = 1+(treeHeight left)+(treeHeight right)

cone :: Tree Int -> Bool
cone Empty = True
cone tree = [1 | k <- [0..(treeHeight tree)-1], (levelSum tree k) > (levelSum tree (k+1))] == []