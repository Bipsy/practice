sumCoins :: Int -> Int -> Int -> Int -> Double
sumCoins pennies nickels dimes quarters = total
	where
		total = fromIntegral (pennies + 5*nickels + 10*dimes + 25*quarters)
