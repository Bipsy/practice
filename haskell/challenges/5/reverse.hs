reverseIt :: ([a] -> [a])
reverseIt [] = []
reverseIt a = reverseAccum a []
	where
			reverseAccum [] b = b
			reverseAccum (x:xs) b = reverseAccum xs (x:b)
