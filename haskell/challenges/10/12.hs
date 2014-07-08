import Data.List

data Element a = Single a | Tuple Int a

encode :: (Eq a) => [a] -> [(Int, a)]
encode xs = map (\x -> (length x,head x)) (group xs)

encodeModified :: Eq a => [a] -> [Element a]
encodeModified = map encodeHelper . encode
    where
      encodeHelper (1,x) = Single x
      encodeHelper (n,x) = Tuple n x

decode :: [Element a] -> [a]
decode = concatenate . unpack
	where
		concatenate = (foldr (++) [])
		unpack = map unpack'
			where 
				unpack' (Single x) = [x]
				unpack' (Tuple count x) = (replicate count x)
