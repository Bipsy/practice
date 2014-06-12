module Fun.Example where
	
	empty :: [[Char]] -> [Char]
	empty [] = "Empty"
	empty (x:xs) = x

	list1 +++ list2 = 	if null list1
						then list2
						else (head list1) : (tail list1 +++ list2)

	reverser :: [a] -> [a]
	reverser list = if null list
					then list
					else (last list) : reverser (init list)

	maxmin :: (Ord a) => [a] -> (a, a)
	maxmin [] = error "List is empty"
	maxmin list = maxmin' (tail list) (head list) (head list)
		where
			maxmin' [] max min = (max,min)
			maxmin' (x:xs) max min
				|	x > max = maxmin' xs x min
				| 	x < min = maxmin' xs max min	
