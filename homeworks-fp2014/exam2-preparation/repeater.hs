--let haskellRepeat = repeater "I love Haskell"

repeater :: String -> (Int -> String -> String)
repeater str = (\count glue -> glueString str count glue)

glueString :: String -> Int -> String -> String
glueString str count glue
  | count == 0 = ""
  | count == 1 = str
  | otherwise = str++glue++(glueString str (count-1) glue)