import Data.List

encode :: (Eq a) => [a] -> [(Int, a)]
encode = map (\ list@(x:xs) -> (length list, x)) . group  
