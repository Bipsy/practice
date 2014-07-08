main = readFile "test.txt" >>= (print . map readInt . words)

--main = do
--	contents <- readFile "test.txt"
--	print . map readInt . words $ contents

readInt :: String -> Int
readInt = read
