pack :: (Eq a) => [a] -> [[a]]
pack [] = []
pack (x:xs) = pack' xs [x] x
	where
		pack' [] (y:ys) _ = (y:ys)
		pack' (x:xs) [] _ = pack' xs [[x]] x
		pack' (x:xs) (y:ys) c
			| x == c 		= pack' xs ((x:y):ys) c
			| otherwise		= pack' xs ([x]:(y:ys)) x
