-- Chaz Del Prato
-- MERGE SORT 
----------

-- merge is a function that uses the Ord class to sort two lists into a sorted list
merge :: Ord a => [a] -> [a] -> [a]
-- if the first list is empty, it will only return the second list
merge [] ys = ys                    -- if one
-- if the second list is empty, it will only return the first list
merge xs [] = xs                    --   or the other list is empty merging is trivial

-- when two lists are not empty, it will perform the following conditions
merge (x:xs) (y:ys) 
    --if the left element of the list is less than or equal to the right element, output the left
  | x <= y    = x : merge xs (y:ys)  
    -- otherwise it will output the right element   
  | otherwise = y : merge (x:xs) ys

msort :: Ord a => [a] -> [a]

-- an empty list is an empty list
msort [] = []
-- if the list has one element, returns that one element
msort [x] = [x]
-- lets the ls, left side and rs, right side be equal to the split at half the length of the list
msort xs = let (ls, rs) = splitAt (length xs `div` 2) xs
                -- calls the merge function to merge the the left side and right side of the list
                in merge (msort ls) (msort rs)

-- QUICK SORT
-----------
-- creates a function that uses the class Ord to take in a list to return a list
qsort :: Ord a => [a] -> [a]

-- an empty list is equal to an empty list
qsort [] = []

-- (pivot:xs)
-- pivot is going to be the first value in the list
-- xs is the rest
qsort (pivot:xs) = 
              -- if the element in xs is less than or equal to the pivot, then it will add it the left list
              qsort[y | y <- xs, y <= pivot]
              -- then concatenates the left side and right side lists with the pivot
              -- ++ is the concatenate operator
              ++ [pivot] ++
              -- if the element in xs is greater than the pivot, then it will add it the right list
              qsort[y | y <- xs, y > pivot]
              
              

-- main outputs to the console
--main = print(msort[4, 65, 2, -31, 0, 99, 2, 83, 782, 1])
-- main outputs to the console
main = print(qsort[4, 65, 2, -31, 0, 99, 2, 83, 782, 1])