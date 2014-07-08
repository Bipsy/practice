module Main where

import Data.Char (toUpper)
import Control.Monad

main = 
	putStrLn "Please type in a string and hit return" >> 
	liftM shout getLine >>=
	putStrLn
	

shout :: [Char] -> [Char]
shout = map toUpper


