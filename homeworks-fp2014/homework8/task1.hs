import Data.Char

encode :: String -> Int -> String
encode "" _ = ""
encode str offset = map (\x -> chr(ord x + offset)) str

decode :: String -> Int -> String
decode "" _ = ""
decode str offset = map (\x -> chr(ord x - offset)) str