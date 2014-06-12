palindrome :: (Eq a) => [a] -> Bool
palindrome a 
	| a == (reverse a) = True
	| otherwise = False
