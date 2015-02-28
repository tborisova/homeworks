type Worm = ([Char], Int)

worms_t = [ ("erdfhgjdr", 44), ("rrrrghrharg", 100),
          ("why i have so many vowels", 66), ("grrragrgh!", 32),
          ("pinky", 14), ("beefcake", 100) ]

getName :: Worm -> String
getName worm = fst worm

getLimit :: Worm -> Int
getLimit worm = snd worm

wormsToEat :: [Worm] -> Int -> [String]
wormsToEat [] _ = []
wormsToEat worms limit = [getName worm | worm <- worms, (eatable worm) >= limit]

eatable :: Worm -> Int
eatable worm = (getLimit worm)*(length (getName worm)) `div` length ([x | x <- getName(worm), elem x "bcdfghjklmnqrstvwxz"])