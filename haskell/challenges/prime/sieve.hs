prime :: Int -> [Int]
prime bound = prime' [2..bound] 2
	where
		prime' list  p
			| p < length list = prime' (step p list) (findP p list)
			| otherwise = list

findP :: Int -> [Int] -> Int
findP _ [] = 0
findP old_p (x:xs) 
	| old_p < x = x
	| otherwise = findP old_p xs

step :: Int -> [Int] -> [Int]
step p list = [n | n <- list, (not (n `mod` p == 0)) || n <= p]
