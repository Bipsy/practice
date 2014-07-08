payback :: Double -> Double
payback charges 
	| charges < 0 = 0
	| charges <= 500 = charges * 0.0025
	| charges <= 1500 = (500 * 0.0025) + (charges-500)*0.0050
	| charges <= 2500 = (500*0.0025)+(1000*0.0050)+((charges-1500)*0.0075)
	| otherwise = (500*0.0025)+(1000*0.0050)+(1000*0.0075)+((charges-2500)*0.01)

