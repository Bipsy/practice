totalProfit :: Int -> Double
totalProfit attendees = gross - cost
	where
		gross = fromIntegral (attendees*5)
		cost = (20 + (fromIntegral attendees)*0.5)
