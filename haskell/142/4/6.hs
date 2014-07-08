main = do
		guess <- getLine
		(print . equation) (read guess)

equation :: Int -> Bool
equation guess = if 4*guess + 2 == 62
					then True
					else False
