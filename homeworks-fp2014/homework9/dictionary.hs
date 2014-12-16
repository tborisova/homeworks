import Data.Char
import Data.List

lowercase'::String->String
lowercase' [] = []
lowercase' (x:xs) = [toLower x]++ lowercase' xs

occurences_of_word :: String -> String -> Int
occurences_of_word "" str1 = 0
occurences_of_word str "" = 0
occurences_of_word word str1 = sum [1 | x <- words str1, length(intersect x word) == length word]

dictionary :: String -> [(String, Int)]
dictionary "" = []
dictionary str1 = nub [(word, occurences_of_word word (lowercase' str1)) | word <- words(lowercase' str1)]
