listLen :: [a] -> Integer
listLen [] = 0
listLen (x:xs) = 1 + listLen xs
