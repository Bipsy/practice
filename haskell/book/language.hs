main = do
	putStrLn "What is your name?"
	name <- getLine
	let output = "Haskell is a great programming language"
	if name == "Simon"
		then putStrLn output
	else if name == "John"
		then putStrLn output
	else if name == "Phil"
		then putStrLn output
	else if name == "Koen"
		then putStrLn "Debugging Haskell is fun"
	else do putStrLn "I don't know who you are"
				
		
