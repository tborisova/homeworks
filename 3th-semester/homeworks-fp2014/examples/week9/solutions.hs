import Data.Char

last'::[a]->Maybe a
last' [] = Nothing
last' [x]  = Just x
last' (x:xs) = last'(xs)

member'::(Eq a) => [a]->a->Bool
member' [] x = False
member' [x] a
  | a == x = True
  | otherwise = False
member' (x:xs) a
  | a == x = True
  | otherwise = member' xs a

range::Int->Int->[Int]
range start end
  | start < end = [start]++(range (start+1) end)
  | start == end = [end]

range'::Int->[Int]
range' start = [start]++(range'(start + 1))

compress::(Eq a) => [a]->[a]
compress [] = []
compress [x] = [x]
compress (first:second:everything_else)
  | first == second = compress(second:everything_else)
  | otherwise = first:(compress (second:everything_else))


-- \x y z -> x + y + z - същото като (lambda(x y z) (+ x y z))
all'::(a->Bool)->[a]->Bool
all' _ [] = True
all' pred (x:xs) 
  | pred x = all' pred xs
  | otherwise = False

any'::(a->Bool)->[a]->Bool
any' _ [] = False
any' pred (x:xs) 
  | pred x = True
  | otherwise = any' pred xs

map'::(a->b)->[a]->[b]
map' _ [] = []
map' func (x:xs) = (func x):(map' func xs)

filter'::(a->Bool)->[a]->[a]
filter' _ [] = []
filter' func (x:xs)
  | func x = x:(filter func xs)
  | otherwise = filter func xs

foldl'::(a->b->b)->b->[a]->b
foldl' _ res [] = res
foldl' func res (x:xs) = (foldl' func (func x res) xs) 

foldr'::(b->a->b)->b->[a]->b
foldr' _ res [] = res
foldr' func res (x:xs) = (foldr' func (func res x) xs) 

reverse'::String->String
reverse' [] = []
reverse' (x:xs) = reverse' xs ++ [x] 

uppercase'::String->String
uppercase' [] = []
uppercase' (x:xs) = [toUpper x]++ uppercase' xs


lowercase'::String->String
lowercase' [] = []
lowercase' (x:xs) = [toLower x]++ lowercase' xs

--dropWhile'::(a->Bool)->[a]->[a]
--dropWhile' func [] = []
--dropWhile' func (x:xs)
--  | func x = xs
--  | otherwise = dropWhile'(func xs)

isPalindrome::[Char]->Bool
isPalindrome str
  | str == (reverse' str) = True
  | otherwise = False
--dropWhile::(a->Bool)->[a]->a
--isPalindrome::[Char]->Bool











