type Worm = (String, Int)

worms = [ ("erdfhgjdr", 44), ("rrrrghrharg", 100),
          ("why i have so many vowels", 66), ("grrragrgh!", 32),
          ("pinky", 14), ("beefcake", 100) ]

wormsToEat :: [Worm] -> Int -> [String]
wormsToEat [] _ = []
wormsToEat worms limit = [name | (name, len) <- worms, eatable (name, len) >= limit]

eatable :: (String, Int ) -> Int
eatable (name, len) = len*(length name) `div` length ([x | x <- name, elem x "bcdfghjklmnqrstvwxz"])