duplicator :: [a] -> [a]
duplicator = foldl (\ acc x -> acc ++ [x,x]) []
