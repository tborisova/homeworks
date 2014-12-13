import Data.Char
-- не може да добавяме елементи
-- !! - елемент на индекс - броя на ! - за списък
-- (1, 2) - извлича първия и втория елемент на n-торка
-- как правим кортеж: (1, 2)
-- взимане на първи елемент fst (1,2) -> 1
-- взимане на 2ри ел : snd (1,2) -> 2
-- кортежите не са хомогненни
-- error "no such element"

first' :: (a, b, c) -> a
first' (a,_,_) = a

second' :: (a, b, c) -> b
second' (_,b,_) = b

third' :: (a, b, c) -> c
third' (_,_,c) = c

zip' :: [a] -> [b] -> [(a, b)]
zip' [a] [b] = [(a,b)]
zip' (x:xs) (y:ys) = [(x, y)]++zip' xs ys

zipWith' ::(a -> b -> c) -> [a] -> [b] -> [c]
zipWith' func [a] [b] = [func a b]
zipWith' func (x:xs) (y:ys) = [func x y]++(zipWith' func xs ys)

findWhere :: (a -> Bool) -> [a] -> Maybe a
findWhere _ [] = Nothing
findWhere func [a]
  | func a = Just a
  | otherwise = Nothing
findWhere func (x:xs)
  | func x = Just x
  | otherwise = findWhere func xs 

type Contact = (String, String)
getName :: Contact -> String
getName contact = fst contact

getNumber :: Contact -> String
getNumber contact = snd contact

type PhoneBook = [Contact]
addContact :: PhoneBook -> Contact -> PhoneBook
addContact phone_book contact = phone_book++[contact]

findContact :: PhoneBook -> String -> Maybe Contact
findContact [] _ = Nothing
findContact phone_book name = findWhere (\a -> getName a == name) phone_book

removeContact :: PhoneBook -> String -> PhoneBook
removeContact [] _ = []
removeContact phone_book name = filter (\a -> getName a /= name) phone_book


lowercase'::String->String
lowercase' [] = []
lowercase' (x:xs) = [toLower x]++ lowercase' xs

hasContact :: PhoneBook -> String -> Bool
hasContact [] _ = False
hasContact phone_book name = any (\a -> lowercase'(getName a) == lowercase' name) phone_book

compose :: (a -> b) -> (c -> a) -> (c -> b)
compose func1 func2 = func1.func2

twice :: (a -> a) -> (a -> a)
twice f = f.f

negate' :: (a -> Bool) -> (a -> Bool)
negate' func  = not.func

flip' :: (a -> b -> c) -> (b -> a -> c)
flip' f a b = f b a

reject :: (a -> Bool) -> [a] -> [a]
reject func list = filter (\a -> func a == False) list

--qsort :: (Ord a) => [a] -> [a]
--qsort [] = []
--qsort [a] = a
--qsort (x:xs) = qsort(filter (\a -> x < a) xs)++qsort(filter (\a -> x >= a) xs)

occurrences :: [a] -> [(a, Int)]
occurrences [] = [(,)]
occurrences [a] = [(a, 1)]
occurrences (x:xs)
  | 