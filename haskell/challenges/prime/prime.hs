main = do
		print ((length . prime) [2..100000])

prime :: [Int] -> [Int]
prime = filter isPrime

isPrime :: Int -> Bool
isPrime num = isPrime' num 2
	where
		isPrime' num divisor = if divisor < num
								then if (mod num divisor) == 0
										then False
										else isPrime' num (divisor+1)
								else True
