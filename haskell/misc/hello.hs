main = putStrLn "Hello" 
		>> getLine 
		>>= (\name -> putStrLn ("Hello, " ++ name ++ "!"))
