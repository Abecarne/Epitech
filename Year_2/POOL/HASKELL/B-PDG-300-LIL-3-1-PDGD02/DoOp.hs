myElem :: Eq a => a -> [a] -> Bool
myElem _ [] = False
myElem x (a:b)
    | x == a = True
    | otherwise = myElem x b

safeDiv :: Int -> Int -> Maybe Int
safeDiv 0 _ = Just 0
safeDiv _ 0 = Nothing
safeDiv x y = Just (x `div` y)

safeNth :: [a] -> Int -> Maybe a
safeNth [] _ = Nothing
safeNth a x = if x == 0
        then Just (head a)
        else safeNth (tail a) (x - 1)

safeSucc :: Maybe Int -> Maybe Int
safeSucc Nothing = Nothing
safeSucc (Just x) = Just (x + 1)

myLookup :: Eq a => a -> [(a, b)] -> Maybe b
myLookup _ [] = Nothing
myLookup x (a:b)
    | x == fst a = Just (snd a)
    | otherwise = myLookup x b

maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo _ Nothing Nothing = Nothing
maybeDo _ Nothing _ = Nothing
maybeDo _ _ Nothing = Nothing
maybeDo a (Just b) (Just c) = Just (a b c)

readInt :: [Char] -> Maybe Int
readInt [] = Nothing
readInt a
    | all (>= "0") [a] && all (<= "9") [a] = Just (read a :: Int)
    | otherwise = Nothing

getLineLength :: IO Int
getLineLength = do
    str <- getLine
    let len = length str
    return len

printAndGetLength :: String -> IO Int
printAndGetLength str =
    (putStrLn str) >>
    return (length str)

repeatLine :: [Char] -> Int -> [[Char]]
repeatLine str x = replicate x str

drawBottomOrTopLine :: Int -> [Char]
drawBottomOrTopLine x
    | x >= 1 = concat ["+", replicate (x*2 - 2) '-', "+"]
    | otherwise = ""

drawMiddleLine :: Int -> [Char]
drawMiddleLine x
    | x >= 1 = concat ["|", replicate (x*2 - 2) ' ', "|"]
    | otherwise = ""

getBottomOrTopLine :: Int -> [Char]
getBottomOrTopLine x = drawBottomOrTopLine x ++ "\n"

getMiddleLine :: Int -> [Char]
getMiddleLine x = concat (repeatLine (drawMiddleLine x ++ "\n") (x - 2))

getBox :: Int -> [Char]
getBox x= getBottomOrTopLine x ++ getMiddleLine x ++ drawBottomOrTopLine x

printBox :: Int -> IO ()
printBox 1 = putStrLn "++"
printBox x
    | x <= 0 = return ()
    | otherwise = putStrLn (getBox x)

concatLines :: Int -> IO String
concatLines x
    | x > 0 = do
        str <- getLine
        otherStr <- concatLines (x - 1)
        return (concat [str ++ otherStr])
    | otherwise = return []

getInt :: IO (Maybe Int)
getInt = readInt <$> getLine
