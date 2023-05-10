namespace random_numbers
{
    class Program
    {
        static void Main(string[] args)
        {
            Random x = new Random();  // Creating a 'Random' object.

            int num = x.Next(1, 7);  // Generating a random number between 1 and 6. First arg is inclusive second arg is exclusive.

            double num1 = x.NextDouble();  // Generates a random float num between 0 and 1.

            Console.WriteLine(num);
        }
    }
}