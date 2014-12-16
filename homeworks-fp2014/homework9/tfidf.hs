import Data.Char
import Data.List

lowercase'::String->String
lowercase' [] = []
lowercase' (x:xs) = [toLower x]++ lowercase' xs

occurences_of_word :: String -> String -> Int
occurences_of_word "" str1 = 0
occurences_of_word str "" = 0
occurences_of_word word str1 = sum [1 | x <- words str1, length(intersect x word) == length word]

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