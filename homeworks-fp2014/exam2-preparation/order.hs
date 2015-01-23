data Order = Online Float Int Int | Offline Float

testOrderOnline :: Order
testOrderOnline = (Online 2.4 1 3)

testOrderOff :: Order
testOrderOff = (Offline 2.4)

isOnline :: Order -> Bool
isOnline (Online price id hours) = True
isOnline (Offline price) = False

timeUntilReceiving :: Order -> Int
timeUntilReceiving (Online price id hours) = hours
timeUntilReceiving (Offline price) = error "offline order"

getPrice :: Order -> Float
getPrice (Online price id hours) = price
getPrice (Offline price) = price

totalPrice :: [Order] -> Float
totalPrice orders = sum [getPrice order | order <- orders]

onlineOrders :: [Order] -> Int
onlineOrders orders = sum [1 | order <- orders, isOnline order]

isExpensive :: Order -> Bool
isExpensive order = getPrice order > 100

instance Show Order where
  show (Online price id hours_for_delivery) = "online order, price "++show price++" id "++show id++" hours_for_delivery "++show hours_for_delivery
  show (Offline price) = "offline order, price "++show price

instance Eq Order where
  (==) (Online price id hours_for_delivery) (Online price2 id2 hours_for_delivery2) = id == id2 && price == price2 && hours_for_delivery == hours_for_delivery2 
  (==) (Offline price) (Offline price2) = price == price2
  (==) _ _ = False