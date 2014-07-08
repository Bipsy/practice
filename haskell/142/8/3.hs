myProduct :: (Num a) => [a] -> a
myProduct = (foldr (*) 1)

containsFiveHuh :: (Eq a) => (Num a) => [a] -> Bool
containsFiveHuh = (foldr 	(\ x y -> if x == 5 
								then True || y 
								else False || y) 
							False)

allEvenHuh :: (Num a) => (Eq a) => (Integral a) => [a] -> Bool
allEvenHuh = (foldr		(\ x y -> if (mod x 2) == 0 
									then y && True
									else y && False)
						True)

allTrueHuh :: [Bool] -> Bool
allTrueHuh = (foldr	(&&) True)


longestString :: [String] -> Int
longestString = (foldr 	(\ x y -> if (length x) > y
									then (length x)
									else y)
						0)


