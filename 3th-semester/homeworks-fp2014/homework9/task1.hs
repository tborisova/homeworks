import Data.List
import Data.Char

merge :: [a] -> [a] -> [a]
merge [] l2 = l2
merge l1 [] = l1
merge l1 l2 = concat [[x,y] | (x,y) <- zip l1 l2]


hammingDistance :: String -> String -> Int
hammingDistance str1 "" = length str1
hammingDistance "" str2 = length str2
hammingDistance str1 str2 = sum [ 1 | (x,y) <- zip str1 str2, x /= y ]


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


occurences_of_word_in_documents :: String -> [String] -> Int
occurences_of_word_in_documents word [] = 0
occurences_of_word_in_documents "" documents = 0
occurences_of_word_in_documents word documents = sum [1 | x <- documents, occurences_of_word word (nub x)  > 0]

tf :: String -> String -> Int
tf str sentence = occurences_of_word str sentence

idf :: String -> String -> [String] -> Float
idf str sentence [] = 0
idf str sentence sentences = logBase (fromIntegral $ tf str sentence) (fromIntegral (length sentences) / (fromIntegral $ occurences_of_word_in_documents str sentences))

tfidf :: String -> String -> [String] -> Float
tfidf str sentence sentences = (fromIntegral $ tf str sentence)*(idf str sentence sentences)



