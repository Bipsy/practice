dupli :: [a] -> Int -> [a]
dupli list n = foldl (\ acc x -> acc ++ (replicate n x)) [] list
