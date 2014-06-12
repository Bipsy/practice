cons8 :: [Int] -> [Int]
cons8 numbers = 8:numbers

end8 :: [Int] -> [Int]
end8 [] = [8]
end8 list = list ++ [8]

headTail :: [a] -> (a, a)
headTail [] = error "List is empty"
headTail (x:xs) = 	if (null xs) 
						then error "List is size 1"
				 	else 
						(x, head (reverse xs))

getFifth :: [a] -> a
getFifth [] = error "List is empty"
getFifth (x:xs) = getFifth' xs 4
	where
		getFifth' [] counter = error "No fifth element"
		getFifth' (x:xs) 0 = x
		getFifth' (x:xs) counter = getFifth' xs (counter-1)

pts :: Int -> Int
pts place 
	| place == 1	= 10
	| place == 2 = 6
	| place == 3 = 4
	| place == 4 = 3
	| place == 5 = 2
	| place == 6 = 1
	| otherwise = 0

revWords :: [Char] -> [Char]
revWords sentence = (unwords . reverse . words) sentence

myFactorial :: (Num a) => (Eq a) => [a] -> [a]
myFactorial [] = []
myFactorial list = myFactorial' list []
	where
		myFactorial' [] result = reverse result
		myFactorial' (x:xs) result = myFactorial' xs ((factorial x):result)
			where 
				factorial 0 = 1
				factorial n = n * factorial (n-1)

doubleFactorial :: (Num a) => (Eq a) => a -> a
doubleFactorial 0 = 1
doubleFactorial 1 = 1
doubleFactorial n = n * doubleFactorial (n-2)

mult :: (Num a) => (Eq a) => a -> a -> a
mult a 0 = 0
mult 0 b = 0
mult a 1 = a
mult a b = a + mult a (b-1)

powerful :: (Num a) => (Eq a) => a -> a -> a
powerful 0 _ = 1
powerful a 0 = 1
powerful a 1 = a
powerful a b = a * powerful a (b-1)

plusOne x = x + 1
addition a 0 = a
addition 0 a = a
addition a b = addition (plusOne a) (b-1)

replicate :: Int -> a -> [a]
replicate 0 _ = []
replicate count element = replicate' count element []
	where
		replicate' 0 _ result = result
		replicate' count element result = replicate' (count-1) element (element:result)

indexOf :: [a] -> Int -> a
indexOf [] _ = error "Index out of bound"
indexOf (x:xs) 0 = x
indexOf (x:xs) index = indexOf xs (index-1)

zipper :: [a] -> [b] -> [(a,b)]
zipper left right = zipper' left right
	where
		zipper' [] _ = []
		zipper' _ [] = []
		zipper' (x:xs) (y:ys) = (x,y):(zipper' xs ys)  	

doubler :: [Integer] -> [Integer]
doubler [] = []
doubler (x:xs) = (2 * x : (doubler xs))

takeInt :: [Int] -> Int -> [Int]
takeInt [] _ = []
takeInt _ 0 = []
takeInt (x:xs) num = x : (takeInt xs (num-1))

dropInt :: [Int] -> Int -> [Int]
dropInt [] _ = []
dropInt list 0 = list
dropInt (x:xs) num = dropInt xs (num-1)

sumInt :: [Int] -> Int
sumInt [] = 0
sumInt (x:xs) = x + sumInt xs

scanSum :: [Int] -> [Int]
scanSum [] = []
scanSum list = scanSum' list 0
	where
		scanSum' [] _ = []
		scanSum' (x:xs) sum = (sum+x):(scanSum' xs (sum+x))

diffs :: [Int] -> [Int]
diffs (x:y:ys) = (y-x):diffs (y:ys)
diffs _ = []
