bind :: (Float -> (Float, String)) -> (Float, String) -> (Float, String)
bind f (a, b) = let
	(c, d) = (f a) in (c, b++d)

unit :: (Float) -> (Float, String)
unit x = (x, "")

lift :: (Float -> Float) -> (Float -> (Float, String))
lift f = unit . f
