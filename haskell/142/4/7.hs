interest :: Double -> Double
interest deposit 
	| deposit < 0 = 0
	| deposit < 1600 = deposit * 1.06 - deposit
	| deposit < 9000 = deposit * 1.075 - deposit
	| otherwise = deposit * 1.08 - deposit
