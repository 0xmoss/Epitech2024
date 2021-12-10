-- 
-- EPITECH PROJECT, 2020
-- B-FUN-300-LYN-3-1-funPoolDay1-
-- File description:
-- My.hs
--

mySucc x = x + 1

myIsNeg x = x < 0

myAbs x = if x < 0 then x * (- 1) else x

myMin x y = if x < y then x else y

myMax x y = if x > y then x else y

myTuple a b = (a, b)

myTruple a b c = (a, b, c)

myFst (a, b) = a

mySnd (a, b) = b

mySwap (a, b) = (b, a)

myTail :: [a] -> [a]
myTail (x:xs) = xs
myTail [] = error "Empty list"

myLength :: [a] -> Int
myLength (x:xs) = 1 + myLength xs
myLength [] = 0

myNth :: [a] -> Int -> a
myNth (x:xs) i = if i < 0 then
    error "Negative index"
else
    (case i >= myLength (x : xs) of
       True -> error "Index out of range"
       False
         -> case i == 0 of
              True -> x
              False -> myNth xs (i - 1))

myTake :: Int -> [a] -> [a]
myTake i (x:xs) = if i >= myLength (x : xs) then
    x : xs
else
    (case i < 0 of
       True -> error "Negative index"
       False
         -> case i == 0 of
              True -> []
              False -> x : myTake (i - 1) xs)

myDrop :: Int -> [a] -> [a]
myDrop i (x:xs) = if i >= myLength (x : xs) then
    []
else
    (case i == 0 of
       True -> (x : xs)
       False -> myDrop (i - 1) xs)

myAppend :: [a] -> [a] -> [a]
myAppend (x:xs) y = x : myAppend xs y
myAppend [] x = x