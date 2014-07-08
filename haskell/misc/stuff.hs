import Control.Monad
import System.Random

safeLog :: (Floating a, Ord a) => a -> Maybe a
safeLog x
	| x >= 0 	= Just (log x)
	| otherwise	= Nothing

safeSqrt :: (Floating a, Ord a) => a -> Maybe a
safeSqrt x 
	| x >= 0 	= Just (sqrt x)
	| otherwise = Nothing

safeLogSqrt :: (Floating a, Ord a) => a -> Maybe a
safeLogSqrt = safeLog <=< safeSqrt

rollDiceIO :: IO (Int, Int)
rollDiceIO = liftM2 (,) (randomRIO (1,6)) (randomRIO (1,6))


--rollNDiceIO :: Int -> IO [Int]
--rollNDiceIO count = rollDice' count
--	where
--		rollDice' count 
--			| count == 0 	= liftM2 []
--			| otherwise 	= liftM2 (:) (randomRIO (1,6)) (rollDice' (count-1))
