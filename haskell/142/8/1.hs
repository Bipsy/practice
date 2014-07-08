data Shape = Circle Double | Square Double

perimeter :: Shape -> Double
perimeter (Circle radius) = (pi*radius*2)
perimeter (Square length) = (4*length)
