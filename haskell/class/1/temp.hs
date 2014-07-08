toDigits :: Integer -> [Integer]
toDigits num 
	| num <= 0 	= []
	| otherwise	= toDigits' num []
		where 
			toDigits' 0 list 	= list
			toDigits' num list 	= toDigits' (num `div` 10) ((num `mod` 10):list)

toDigitsRev :: Integer -> [Integer]
toDigitsRev num
	| num <= 0 	= []
	| otherwise	= toDigitsRev' num
		where
			toDigitsRev' 0		= []
			toDigitsRev' num	= (num `mod` 10):toDigitsRev' (num `div` 10)

doubleEveryOther :: [Integer] -> [Integer]
doubleEveryOther list = [f x | (x, f) <- zip list $ cycle [(*2), id]]

sumDigits :: [Integer] -> Integer
sumDigits nums = foldr (+) 0 (map (sum . toDigits) nums)

validate :: Integer -> Bool
validate num 
	| (((sumDigits . doubleEveryOther . toDigits) num) `mod` 10 == 0) = True
	| otherwise 													  = False


type Peg 	= String
type Move	= (Peg, Peg)

hanoi :: Integer -> Peg -> Peg -> Peg -> [Move]
