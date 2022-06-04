mySucc :: Int -> Int
mySucc x = x + 1

myIsNeg :: Int -> Bool
myIsNeg x = x < 0

myAbs :: Int -> Int
myAbs x
    | x >= 0 = x
    | otherwise = -x

myMin :: Int -> Int -> Int
myMin x y
    | x <= y = x
    | otherwise = y

myMax :: Int -> Int -> Int
myMax x y
    | x >= y = x
    | otherwise = y

myTuple :: a -> b -> (a, b)
myTuple a b = (a, b)

myTruple :: a -> b -> c -> (a, b, c)
myTruple a b c = (a, b, c)

myFst :: (a, b) -> a
myFst (a, b) = a

mySnd :: (a, b) -> b
mySnd (a, b) = b

mySwap :: (a, b) -> (b, a)
mySwap (a, b) = (b, a)

myHead :: [a] -> a
myHead (x:_) = x
myHead [] = error "Empty list"

myTail :: [a] -> [a]
myTail (_:a) = a
myTail [] = error "Empty list"

myLength :: [a] -> Int
myLength [] = 0
myLength (_:a) = 1 + myLength a

myNth :: [a] -> Int -> a
myNth [] _ = error "Empty list"
myNth (a:b) x = if x == 0
        then myHead (a:b)
        else myNth b (x - 1)

myTake :: Int -> [a] -> [a]
myTake _ [] = []
myTake 0 _ = []
myTake x (a:b)
    | x < 0 = error "Negative index"
    | otherwise = a : myTake (x - 1) b

myDrop :: Int -> [a] -> [a]
myDrop _ [] = []
myDrop 0 a = a
myDrop x (a:b)
    | x < 0 = error "Negative index"
    | otherwise = myDrop (x - 1) b

myAppend :: [a] -> [a] -> [a]
myAppend [] b = b
myAppend a [] = a
myAppend (a:ax) b = a : myAppend ax b

myReverse :: [a] -> [a]
myReverse [] = []
myReverse (a:b) = myAppend (myReverse b) [a]

myInit :: [a] -> [a]
myInit [] = error "Empty list"
myInit a = myReverse (myTail (myReverse a))

myLast :: [a] -> a
myLast [] = error "Empty list"
myLast a = myHead (myReverse a) 

myZip :: [a] -> [b] -> [(a, b)]
myZip [] _ = []
myZip _ [] = []
myZip (a:b) (a':b') = (a, a') : myZip b b'

myUnzip :: [(a,b)] -> ([a], [b])
myUnzip [] = ([], [])
myUnzip x = (myMap myFst x, myMap mySnd x)

myMap :: (a -> b) -> [a] -> [b]
myMap a [] = []
myMap a (b:b') = (a b) : myMap a b'