type Book = (String, Int) 

books :: [Book]
books = [ ("To Kill A Mockingbird", 324), ("1984", 328),
          ("The Catcher in the Rye", 277), ("The Great Gatsby", 180),
          ("Harry Potter and the Sorcerer's Stone", 310),
          ("The Little Prince", 84), ("Animal Farm", 112),
          ("The Hobbit", 365) ]

getName :: Book -> String
getName book = fst book

getPages :: Book -> Int
getPages book = snd book

booksToEat :: [Book] -> Int -> [String]
booksToEat [] _ = []
booksToEat books limit = [getName book | book <- books, delicioussness book >= limit]

delicioussness :: Book -> Int
delicioussness book = ((getPages book) * (glasni (getName book))) `div` (length $ getName book)

glasni :: String -> Int
glasni name = sum [1 | x <- name, elem x "aeiouyAEIOUY"]