import Data.Function (on)
import Data.Monoid (mappend)
import Data.List (sortBy)
import Data.Ord
import Data.List

-- Creates a person boject
data Person = Person String Int deriving (Show, Eq)
name::Person->String
name (Person n a) = n
age::Person->Int
age (Person n a) = a

-- QUICK SORT:
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


-- performs the qsort on the numbers
numbers = print(qsort[645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26])

--sets a list of people
people = [Person "Hal" 20, Person "Susann" 31, Person "Dwight" 19, Person "Kassandra" 21, Person "Lawrence" 25, Person "Cindy" 22, Person "Cory" 27, Person "Mac" 19, Person "Romana" 27, Person "Doretha" 32, Person "Danna" 20, Person "Zara" 23, Person "Rosalyn" 26, Person "Risa" 24, Person "Benny" 28, Person "Juan" 33, Person "Natalie" 25]

--uses the sortby clause to sort the people list by the name of the person
peopleOrderedByNameToAge = sortBy nameThenAge people
    where nameThenAge = 
              (compare `on` name) `mappend` (compare `on` age) 

--runs the test
test2 = print(peopleOrderedByNameToAge)

--uses the sortby clause to sort the people list by the age of the person
--not able to get it decending
peopleOrderedByAgeToName = sortBy ageThenName people
    where ageThenName = 
              (compare `on` age) `mappend` (compare `on` name) 

test3 = print( peopleOrderedByAgeToName)