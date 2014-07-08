import Data.List

data Element a = Tuple Int a | Single a
	deriving Show

encode :: (Eq a) => [a] -> [(Int, a)]
encode = map (\ list@(x:xs) -> (length list, x)) . group

encodeModified :: (Eq a) => [a] -> [Element a]
encodeModified = map encode' . encode
	where
		encode' (1,x) = Single x
		encode' (n,x) = Tuple n x
