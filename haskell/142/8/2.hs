data Animal = Spider Int Double | Elephant Double | Monkey Int Double
	deriving Show

fitsHuh :: Animal -> Double -> Bool
fitsHuh (Spider legs m_space) space = m_space < space
fitsHuh (Elephant m_space) space = m_space < space
fitsHuh (Monkey intell m_space) space = m_space < space

getSpace :: Animal -> Double
getSpace (Spider legs m_space) = m_space
getSpace (Elephant m_space) = m_space
getSpace (Monkey intell m_space) = m_space


biggest :: Animal -> Animal -> Animal
biggest a b = if (getSpace a) > (getSpace b)
				then a
				else b
