import System.Environment ( getArgs )
import System.Exit ()

mySwap :: ([Int], [Int]) -> ([Int], [Int])
mySwap (a, b) = (b, a)

castIntList :: [String] -> [Int]
castIntList = map read

doOp :: String -> ([Int], [Int]) -> ([Int], [Int])
doOp str lists
    | str == "sa" = swap lists
    | str == "sb" = mySwap (swap (mySwap lists))
    | str == "sc" = swap (mySwap (swap (mySwap lists)))
    | str == "pa" = putfirst lists
    | str == "pb" = mySwap (putfirst (mySwap lists))
    | str == "ra" = rotate lists
    | str == "rb" = mySwap (rotate (mySwap lists))
    | str == "rr" = rotate (mySwap (rotate (mySwap lists)))
    | str == "rra" = rorotate lists
    | str == "rrb" = mySwap (rorotate (mySwap lists))
    | str == "rrr" = rorotate (mySwap (rorotate (mySwap lists)))
    | otherwise = lists

dispatchOpe :: [[Char]] -> ([Int], [Int]) -> ([Int], [Int])
dispatchOpe [] liste = liste
dispatchOpe (op:ops) listes = dispatchOpe ops (doOp op listes)

main :: IO ()
main = do
    x <- getArgs
    op <- getLine
    let input = castIntList x
    let ops = words op
    let final_lists = dispatchOpe ops (input, [] :: [Int])
    if isSorted (fst final_lists)
        then putStrLn "OK"
        else putStrLn "KO"

isSorted :: [Int] -> Bool
isSorted [] = True
isSorted [_] = True
isSorted (a:b:nbs) = (a <= b) && isSorted (b:nbs)

swap :: ([Int], [Int]) -> ([Int], [Int])
swap ([], []) = ([], [])
swap ([], bs) = ([], bs)
swap ([a], bs) = ([a], bs)
swap (a:b:as, []) = (b:a:as, [])
swap (a:b:as, bs) = (b:a:as, bs)

putfirst :: ([Int], [Int]) -> ([Int], [Int])
putfirst ([], []) = ([], [])
putfirst (a, []) = (a, [])
putfirst (a, b:c) = (b:a, c)

rotate :: ([Int], [Int]) -> ([Int], [Int])
rotate ([], []) = ([], [])
rotate ([], bs) = ([], bs)
rotate (a:as, bs) = (reverse (a:reverse as), bs)

rorotate :: ([Int], [Int]) -> ([Int], [Int])
rorotate ([], []) = ([], [])
rorotate ([], bs) = ([], bs)
rorotate (a:b, bs) = (last (a:b) : init (a:b), bs)