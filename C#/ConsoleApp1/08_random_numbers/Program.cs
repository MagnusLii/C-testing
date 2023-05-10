namespace random_numbers
{
    class Program
    {
        static void Main(string[] args)
        {
            Random x = new Random();  // Creating a 'Random' object.

            int num = x.Next(1, 6);  // Generating a random number between 1 and 6. First arg is inclusive second arg is exclusive.

            Console.WriteLine(num);
        }
    }
}