sign :: Double -> String
sign num 
	| num < 0 = "negative"
	| num > 0 = "positive"
	| otherwise = "zero"
