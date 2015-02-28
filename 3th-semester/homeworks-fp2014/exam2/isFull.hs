data Tree a = Empty | Node a (Tree a) (Tree a)

fullTree = Node 1
        (Node 2
            (Node 3 Empty Empty)
            (Node 4 Empty Empty))
        (Node 5 Empty Empty)
nonFullTree = Node 1
            (Node 2
                (Node 3 Empty Empty)
                (Node 4 Empty Empty))
            Empty

isFull :: Tree a -> Bool
isFull Empty = False
isFull (Node root Empty Empty) = True
isFull (Node root left Empty) = False
isFull (Node root Empty right) = False
isFull (Node root left right) = isFull left && isFull right