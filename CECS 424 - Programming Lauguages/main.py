# sorts the numbers list with built in sort
numbers = [645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26]
numbers.sort()
print(*numbers, "\n")

#creates a person class
class Person:
  def __init__(self, name, age):
    self.name = name
    self.age = age
  def __str__(self):
    return str(self.name) + "\t" + str(self.age) + "\n"

# creates a list of people
people = [Person("Hal", 20), Person("Susann", 31),
          Person("Dwight", 19), Person("Kassandra", 21), 
			    Person("Lawrence", 25), Person("Cindy", 22), 
          Person("Cory", 27), Person("Mac", 19),
          Person("Romana", 27), Person("Doretha", 32),
          Person("Danna", 20), Person("Zara", 23), 
          Person("Rosalyn", 26), Person("Risa", 24), 
          Person("Benny", 28), Person("Juan", 33), 
          Person ("Natalie", 25)]

# sorts the people by their name
people.sort(key = lambda Person: Person.name)
print(*people, "\n")
# sorts the people by their age and reverses the order to show decending
people.sort(key = lambda Person: Person.age, reverse=True)
print(*people, "\n")