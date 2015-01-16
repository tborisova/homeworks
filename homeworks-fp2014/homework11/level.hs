data Tree a = Empty | Node a (Tree a) (Tree a)

testTree :: Tree Int
testTree = Node 11
                (Node 7
                    (Node 4 Empty Empty)
                    (Node 9 Empty Empty))
                (Node 21 Empty Empty)

member::(Eq a) => a -> Tree a -> Bool
member _ Empty = False
member num (Node root left right) = root == num || (member num left) || (member num right)

pathTo :: (Ord a) => a -> Tree a -> [a]
pathTo _ Empty = []
pathTo x (Node root left right)
  | not $ member x (Node root left right) = error "exception, no path" 
  | x == root = [root]
  | x > root = [root]++pathTo x right
  | x < root = [root]++pathTo x left

level :: (Ord a) => Int -> Tree a -> [a]
level _ Empty = []
level num (Node root left right)
  | num == 1 = [root]
  | length(pathTo root (Node root left right)) == num = (level (num-1) left)++(level (num-1) right)
  | otherwise = (level (num-1) left)++(level (num-1) right)