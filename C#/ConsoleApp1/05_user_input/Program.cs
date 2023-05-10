namespace user_input
{
    class Program
    {
        static void Main(string[] args)
        {
            // Userinput

            Console.Write("Enter your name?: ");
            String name = Console.ReadLine();  // Console.ReadLine() takes userinput from the console and sets it as the var value.

            Console.Write("Whats your age?: ");
            int age = Convert.ToInt32(Console.ReadLine());  // Converting user input to Int.

            Console.WriteLine("Hello " + name);
            Console.WriteLine("You are " + age + " years old.");
        }
    }
}