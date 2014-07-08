module Main where

import Happstack.Lite

main :: IO ()
main = serve Nothing myApp

myApp :: ServerPart Response
myApp = msum [homepage]

homepage :: ServerPart Response
homepage = ok "My name is Peter Anderson. I am trying to build a simple, clean, and robust website using Haskell. I do not know Haskell very well, but I am trying to learn and I thought this would be a good thing to try.\n"
