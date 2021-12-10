--
-- EPITECH PROJECT, 2020
-- pushswapTest
-- File description:
-- test.hs
--

import System.Environment
import Data.List

type Data = ([Int], [Int])

-- MAIN
main :: IO()
main = do
    args <- getArgs
    let arg = getIntStr args
    line <- getLine
    let res = exec

    if isSorted arg == True then
        putStrLn "OK"
    else
        putStrLn "KO"

command_list :: [String]
command_list = [
    "sa",
    "sb",
    "sc",
    "pa",
    "pb",
    "ra",
    "rb",
    "rr",
    "rra",
    "rrb",
    "rrr" ]

exec :: String -> Data -> Maybe Data
exec "sa" (x:y:xs, l_b) = Just (y:x:xs, l_b)
exec "sb" (l_a, x:y:xs) = Just (l_a, y:x:xs)
exec "sc" thread = exec "sa" thread >>= exec "sb"

exec "pa" (l_a, y:ys) = Just (y:l_a, ys)
exec "pb" (x:xs, l_b) = Just (xs, x:l_b)

exec "ra" (x:xs, l_b) = Just (xs++[x], l_b)
exec "rb" (l_a, x:xs) = Just (l_a, xs++[x])

exec "rr" thread = exec "ra" thread >>= exec "rb"
exec "rra" (l_a, l_b) = Just (last l_a : init l_a, l_b)
exec "rrb" (l_a, l_b) = Just (l_a, last l_b : init l_b)
exec "rrr" thread = exec "rra" thread >>= exec "rrb"

exec com thread | com `elem` command_list = Just thread
exec _ _ = Nothing

-- TOOLS
-- isSorted
isSorted :: (Ord a) => [a] -> Bool
isSorted [] = True
isSorted [x]= True
isSorted (x:y:xs) = x <= y && isSorted (y:xs)

-- getIntStr
getIntStr :: [String] -> [Int]
getIntStr a = fmap read a