module PutJSON where

import SimpleJSON
import Data.List (intercalate)

renderJValue :: JValue -> String
renderJValue (JString s) = show s
renderJValue (JNumber n) = show n
renderJValue (JBool b) 
	| b == True = "true"
	| otherwise = "false"
renderJValue JNull = "null"
renderJValue (JObject o)  = "{" ++ pairs o ++ "}"
	where 
		pairs [] = ""
		pairs ps = intercalate ", " (map renderPair ps)
		renderPair (k,v) = show k ++ ": " ++ renderJValue v
renderJValue (JArray a) = "[" ++ values a ++ "]"
	where
		values [] = ""
		values vs = intercalate ", " (map renderJValue vs) 
	
putJValue :: JValue -> IO ()
putJValue value = putStrLn (renderJValue value)
