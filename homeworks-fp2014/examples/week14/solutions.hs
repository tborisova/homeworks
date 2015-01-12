data Vector2d = Vector2d Float Float
--data Vector2d = Vector2d {x:Float y:Float}
  -- value constructors - тези дето са в дясната част на =
-- Eq, Ord, Show - type classes - interface in Java, abstract class in C++ и се имплементират методи

addVectors::Vector2d -> Vector2d -> Vector2d
addVectors (Vector2d x1 y1) (Vector2d x2 y2) = Vector2d (x1 + x2) (y1+ y2)

instance Show Vector2d where
    show (Vector2d x y)  = "Vector2d: "++show[x,y]

vectorLength::Vector2d -> Float
vectorLength (Vector2d x y) = sqrt(x^2 + y^2)

dotProduct::Vector2d -> Vector2d -> Float
dotProduct (Vector2d x1 y1) (Vector2d x2 y2) = x1*x2 + y1*y2

instance Eq Vector2d where
    (==) (Vector2d x1 y1) (Vector2d x2 y2)  = x1 == x2 && y1 == y2

data Shape = Rect Float Float | Circle Float

area::Shape -> Float
area (Circle r) = pi*r^2
area (Rect a b) = a*b

isRect::Shape -> Bool
isRect (Circle r) = False
isRect (Rect a b) = True

instance Show Shape where
    show (Circle r)  = "Circle with r: "++show r
    show (Rect a b)  = "Rect with a, b: "++show[a,b]

instance Eq Shape where
    (==) (Rect x1 y1) (Rect x2 y2)  = x1 == x2 && y1 == y2
    (==) (Circle r1) (Circle r2)  = r1 == r2
    (==) _ _ = False

data Tree a = Empty | Node a (Tree a) (Tree a)

testTree = Node 7 (Node 5 (Node 2 Empty Empty) (Node 6 Empty Empty)) (Node 24 Empty Empty)

treeHeight::Tree a -> Int
treeHeight Empty = 0
treeHeight (Node root left right) = 1 + max (treeHeight right) (treeHeight left)  

member::(Eq a) => a -> Tree a -> Bool
member _ Empty = False
member num (Node root left right) = root == num || (member num left) || (member num right)

member'::(Ord a) => a -> Tree a -> Bool
member' _ Empty = False
member' num (Node root left right)
  | root == num = True
  | root < num = member' num right
  | root > num = member' num left

isBalanced :: Tree a -> Bool
isBalanced Empty = True
isBalanced (Node root left right) = (treeHeight right) - (treeHeight left) <= 1

inOrder :: Tree a -> [a]
inOrder Empty = []
inOrder (Node root left right) = (inOrder left)++[root]++(inOrder right)

preOrder :: Tree a -> [a]
preOrder Empty = []
preOrder (Node root left right) = [root]++(preOrder left)++(preOrder right)

postOrder :: Tree a -> [a]
postOrder Empty = []
postOrder (Node root left right) = (postOrder left)++(postOrder right)++[root]

insert :: (Ord a) => a -> Tree a -> Tree a
insert element Empty = (Node element Empty Empty)
insert el (Node root left right)
  | el == root = (Node root left right)
  | el > root = (Node root left (insert el right))
  | el < root = (Node root (insert el left) right) 
  

--instance Show Tree where
--    show (Node root left right)  = "Root: "++show root++" Left: "++show left++" Rigth tree"++ show right
