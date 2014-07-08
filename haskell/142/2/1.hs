tip :: Double -> Double
tip a = a * 1.15

shareWithTip :: Double -> Double -> Double
shareWithTip cost pieces = tip ((cost / 8) * pieces)
