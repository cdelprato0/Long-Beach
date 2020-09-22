//Assignment 3
//Chaz Del Prato
using System;
using System.Collections.Generic;
using System.Linq;

namespace lab3_424
{
//create a struct that contains attributes of a person
    struct Person
    {
        public string name;
        public int age;
    }
    class Program
    {
        //a generic print for almost all types
        public static void print<T>(IList<T> content)
        {
            //goes through each item in the container
            foreach (T item in content)
            {
                System.Console.WriteLine(item.ToString());
            }
        }

        static void Main(string[] args)
        {
            //array with all the values
            double[] numbers = { 645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26 };
    
            //list of all people
            IList<Person> people = new List<Person>();
            people.Add(new Person() { name = "Hal", age = 20 });
            people.Add(new Person() { name = "Susann", age = 31 });
            people.Add(new Person() { name = "Dwight", age = 19 });
            people.Add(new Person() { name = "Kassandra", age = 21 });
            people.Add(new Person() { name = "Lawrence", age = 25 });
            people.Add(new Person() { name = "Cindy", age = 22 });
            people.Add(new Person() { name = "Cory", age = 27 });
            people.Add(new Person() { name = "Mac", age = 19 });
            people.Add(new Person() { name = "Romana", age = 27 });
            people.Add(new Person() { name = "Doretha", age = 32 });
            people.Add(new Person() { name = "Danna", age = 20 });
            people.Add(new Person() { name = "Zara", age = 23 });
            people.Add(new Person() { name = "Rosalyn", age = 26 });
            people.Add(new Person() { name = "Risa", age = 24 });
            people.Add(new Person() { name = "Benny", age = 28 });
            people.Add(new Person() { name = "Juan", age = 33 });
            people.Add(new Person() { name = "Natalie", age = 25 });

            //Uses .OrderBy to order the list by the given phrase. sorted by name
            IEnumerable<Person> byName = people.OrderBy(person => person.name);
            //Uses .OrderByDecending to order the list by the given phrase. sorted by age in decending order
            IEnumerable<Person> decendingAge = people.OrderByDescending(person => person.age);

            //print to the console
            Console.WriteLine("Numbers:");
            print(numbers);
            //calls the sorting algor for arrays
            Array.Sort(numbers);
            Console.WriteLine("\nNumbers Sorted:");
            print(numbers);
            
            //prints out the people by using the orderby clause
            Console.WriteLine("\nPeople sorted by name:");
            foreach (Person person in byName)
            {
                Console.WriteLine("{0} \t {1}", person.name, person.age);
            }
            Console.WriteLine("\nPeople sorted by Age:");
            foreach (Person person in decendingAge)
            {
                Console.WriteLine("{0} \t {1}", person.name, person.age);
            }
            
        }
    }
}
