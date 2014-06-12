compress :: (Eq a) => [a] -> [a]
compress [] = []
compress a = compress' a []
	where
			compress' [] b = b
			compress' a [] = compress' (init a) [(last a)]
			compress' a b
				| (head b) == (last a) 	= compress' (init a) b
				| otherwise 			= compress' (init a) ((last a):b)
