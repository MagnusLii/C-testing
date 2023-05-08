namespace ConsoleApp1
{
    internal class variables
    {
        static void Main(string[] args)
        {
            int x;  // declaration.
            x = 1337;  // initialization.
            int y = 69;  // declaration + initialization.
            int z = x + y;
            int age = 30;

            double height = 50.5; // double == float number.

            bool alive = false; // bool == Boolean.

            char symbol = '@'; // char == character (singular) character must be within single quotes.

            String name = "N/A"; // String starts with capital S.
            String UserName = symbol + name;

            Console.WriteLine("Hello " + name);
            Console.WriteLine("Your age is " + age);
            Console.WriteLine("Height = " + height);
            Console.WriteLine("Are you alive? " + alive);
            Console.WriteLine("Your username is " + UserName);


        }
    }
}
