{-# OPTIONS_GHC -Wall #-}
module LogAnalysis where

import Log
import Data.List

parseMessage :: String -> LogMessage
parseMessage [] 	= Unknown "Empty String"
parseMessage line@(x:_) = 
	case x of
		'I' -> LogMessage Info 	(read (extracWord line 1)) 
								(extractMessage line 2)
		'W' -> LogMessage Warning (read (extracWord line 1)) 
								(extractMessage line 3)
		'E' -> LogMessage 	(Error (read (extracWord line 1))) 
							(read (extracWord line 2))
							(extractMessage line 3)
		_ -> Unknown line

extracWord :: String -> Int -> String
extracWord line index = ((words line) !! index)

extractMessage :: String -> Int -> String
extractMessage line index = intercalate " " (drop index (words line))

getTimeStamp :: LogMessage -> Int
getTimeStamp (LogMessage _ timestamp _) = timestamp
getTimeStamp (Unknown _) 				
	= error "Unknown messages do not have time stamps"


getMessage :: LogMessage -> String
getMessage (LogMessage _ _ message) = message
getMessage (Unknown _) = error "Unknown messages do not have messages"

parse :: String -> [LogMessage]
parse = map parseMessage . lines


insert :: LogMessage -> MessageTree -> MessageTree
insert (Unknown _) tree 				= tree
insert message Leaf 					= Node Leaf message Leaf
insert message (Node left item right) 	
	|  	(getTimeStamp message) > (getTimeStamp item) 
		= (Node left item (LogAnalysis.insert message right))
	| 	(getTimeStamp message) < (getTimeStamp item) 
		= (Node (LogAnalysis.insert message left) item right)
	| 	otherwise = error "That time stamp has already been inserted"


build :: [LogMessage] -> MessageTree
build = foldr (\ ele acc -> LogAnalysis.insert ele acc) Leaf


inOrder :: MessageTree -> [LogMessage]
inOrder Leaf 					= []
inOrder (Node left item right) 	= (inOrder left) ++ [item] ++ (inOrder right)


severeErrors :: [LogMessage] -> [LogMessage]
severeErrors = filter 
				(\ message -> 
					case message of
						(LogMessage (Error num) _ _) 
							-> if num >= 50 
								then True
								else False
						(LogMessage Info _ _) -> False
						(LogMessage Warning _ _) -> False
						(Unknown _) -> False)		


convertToMessage :: [LogMessage] -> [String]
convertToMessage = foldr (\ ele acc -> (getMessage ele):acc) [] 
							


whatWentWrong :: [LogMessage] -> [String]
whatWentWrong list = (convertToMessage . inOrder . build . severeErrors) list
