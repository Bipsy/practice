nextToLast :: ([a] -> a)
nextToLast a = reverse a !! 1

nextToLastComp :: ([a] -> a)
nextToLastComp = last . init

double :: Int -> Int
double = doubler

doubler :: Int -> Int
doubler x = 2 * x
