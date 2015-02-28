data Tree a = Empty | Node a (Tree a) (Tree a)

testTree :: Tree Int
testTree = Node 11
                (Node 7
                    (Node 4 Empty Empty)
                    (Node 9 Empty Empty))
                (Node 21 Empty Empty)

level :: Int -> Tree a -> [a]
level 0 _ = []
level _ Empty = []
level number (Node root left right)
	| number == 1 = [root]
	| otherwise = (level number-1 left)++(level number-1 right)