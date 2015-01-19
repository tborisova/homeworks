-- ляво после дясно

data Tree a = Empty | Node a (Tree a) (Tree a) deriving (Show, Eq)

testTree :: Tree Int
testTree2 :: Tree Int
testTree = Node 7 (Node 5 (Node 2 Empty Empty) (Node 6 Empty Empty)) (Node 24 Empty Empty)
testTree2 = Node 7 (Node 5 (Node 2 Empty Empty) (Node 6 Empty Empty)) (Node 1 Empty Empty)

sumTree :: Tree Int -> Int
sumTree Empty = 0
sumTree (Node root Empty Empty) = root
sumTree (Node root left right) = root + sumTree left + sumTree right

minTree :: Tree Int -> Int
minTree Empty = error "can't get min element of empty tree"
minTree (Node root Empty Empty) = root
minTree (Node root left Empty) = min root (minTree left)
minTree (Node root Empty rigth) = min root (minTree rigth)
minTree (Node root left rigth) = min (min root (minTree left)) (minTree rigth)
--minimum [root, minTree left, minTree right]
-- (Eq a) => (Tree a) show 
data Expression = I Int | Add Expression Expression | Mult Expression Expression

testExp :: Expression
testExp = (Add (I 3) (Mult (I 4) (I 10)))

eval :: Expression -> Int
eval (I a) = a
eval (Add exp1 exp2) = (eval exp1) + (eval exp2)
eval (Mult exp1 exp2) = (eval exp1) * (eval exp2)

data Order = Online Float Int Int | Offline Float
type ShoppingCart = [Order]

testOrderOnline :: Order
testOrderOnline = (Online 2.4 1 3)

testOrderOff :: Order
testOrderOff = (Offline 2.4)

isOnline :: Order -> Bool
isOnline (Online price id hours_for_delivery) = True
isOnline (Offline price) = False

timeUntilReceiving :: Order -> Int
timeUntilReceiving (Online price id hours_for_delivery) = hours_for_delivery
timeUntilReceiving (Offline price) = error "the order is ofline"

getPrice :: Order -> Float
getPrice (Online price id hours_for_delivery) = price
getPrice (Offline price) = price

totalPrice :: [Order] -> Float
totalPrice orders = sum [getPrice x | x <- orders]

onlineOrders :: [Order] -> Int
onlineOrders orders = sum [ 1 | x <- orders, isOnline x]

isExpensive :: Order -> Bool
isExpensive (Offline price) = price > 100
isExpensive (Online price id hours_for_delivery) = price > 100

instance Show Order where
  show (Online price id hours_for_delivery) = "online order, price "++show price++" id "++show id++" hours_for_delivery "++show hours_for_delivery
  show (Offline price) = "offline order, price "++show price

instance Eq Order where
  (==) (Online price id hours_for_delivery) (Online price2 id2 hours_for_delivery2) = id == id2 && price == price2 && hours_for_delivery == hours_for_delivery2 
  (==) (Offline price) (Offline price2) = price == price2
  (==) (Online price2 id hours_for_delivery) (Offline price) = False
  (==) (Offline price) (Online price2 id hours_for_delivery)= False

data Employee = Employee String Int String Int

type Department = [Employee]

emp1 :: Employee
emp1 = (Employee "naame" 18 "dev" 200)

emp2 :: Employee
emp2 = (Employee "naame2" 19 "manager" 400)

dept :: Department
dept = [emp1, emp2]

paycheck :: Employee -> Int
paycheck (Employee name age position pay) = pay

expenses :: Department -> Int
expenses department = sum [paycheck employee | employee <- department]

isManager :: Employee -> Bool
isManager (Employee name age position pay) = position == "manager"

hasManager :: Department -> Bool
hasManager department = length [employee | employee <- department, isManager employee] == 1

levelSum :: Tree Int -> Int -> Int
levelSum Empty _ = 0
levelSum (Node root left right) level
  | level == 0 = root
  | otherwise = (levelSum left (level-1)) + (levelSum right (level-1))

--levelMax :: Tree Int -> Int -> Int
--levelMax Empty _ = error "exception empty tree"
--levelMax (Node root left right) lev
--  | lev == 0 = root
--  | otherwise = maximum [root, levelMax left (lev-1), levelMax right (lev-1)] 

treeHeight::Tree Int -> Int
treeHeight Empty = 0
treeHeight (Node root left right) = 1 + max (treeHeight right) (treeHeight left)  

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

cone :: Tree Int -> Bool
cone Empty = True
cone (Node root Empty Empty) = False
cone tree = length [ 1 | level_up <- [0..(treeHeight tree - 1)], levelSum tree level_up >= levelSum tree (level_up+1) && (length $ (level level_up+1) tree) /= 0] == 0










