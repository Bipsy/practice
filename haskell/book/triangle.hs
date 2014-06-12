main = do
	putStrLn "The base?"
	base <- getLine
	putStrLn "The height?"
	height <- getLine
	putStrLn ("The area of the triangle is " ++ show (0.5 * read base * read height))
