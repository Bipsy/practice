describesLetter :: Char -> String
describesLetter letter = 
	if letter >= 'a' && letter <= 'z'
		then "The letter is lower case."
	else if letter >= 'A' && letter <= 'Z'
		then "The letter is upper case."
	else "Not an ASCII letter"

primeNumberExtractor :: [Int] -> [Int]
primeNumberExtractor [] = []
primeNumberExtractor numbers = prime numbers []
	where
		prime [] result = result
		prime (x:xs) result 
			| (isPrime x) 	= prime xs (x:result)
			| otherwise 	= prime xs result

isPrime :: Int -> Bool
isPrime number = isPrime' number 2
	where
		isPrime' number divisor
			| (number mod divisor == 0) 	= False
			| divisor < number 			= isPrime' number (divisor+1)
			| otherwise 				= True	
