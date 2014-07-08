module Main where

import Control.Monad


main = printer ["Butter", "Bomb", "Taco"]

printer :: [String] -> IO ()
printer =  foldr1 (\ x y -> putStrLn x)
