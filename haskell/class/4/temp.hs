module Temp where

fun :: [Integer] -> Integer
fun = product . map (subtract 2) . filter even

fun2 :: Integer -> Integer
fun2 = sum . takeWhile (> 1) . iterate (`div` 2)

xor :: [Bool] -> Bool
xor = foldr (\ ele acc -> (ele && (not acc)) || ((not ele) && acc)) False

map' :: (a -> b) -> [a] -> [b]
map' f = foldr (\ ele acc -> ((f ele) : acc)) []
			
