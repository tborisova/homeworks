import Data.Char
import Data.List
import Data.String

nextStates :: [[String]] -> String -> [[[String]]]
nextStates [[]] _ = [[]]
nextStates (first_row:second_row:third_row) player
	| any (\element -> length(intersect element player) == 0) first_row = nextStates((first_row:second_row:third_row) player)++(makeNewRow(player first_row):second_row:third_row) player
	| any (\element -> length(intersect element player) == 0) second_row = nextStates((first_row:second_row:third_row) player)++(first_row:makeNewRow(player second_row):third_row) player
	| any (\element -> length(intersect element player) == 0) third_row = nextStates((first_row:second_row:third_row) player)++(first_row:second_row:makeNewRow(player third_row)) player
	| otherwise = (first_row:second_row:third_row)

makeNewRow :: String -> [String] -> [String]
makeNewRow player (first_string:second_string:third_string)
	| first_string == "-" = (player:second_string:third_string)
	| second_string == "-" = (first_string:player:third_string)
	| third_string == "-" = (first_string:second_string:player)
