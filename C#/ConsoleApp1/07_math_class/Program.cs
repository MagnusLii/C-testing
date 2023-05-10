namespace math_class
{
    class Program
    {
        static void Main(string[] args)
        {
            double x = 3.14;

            double a = Math.Pow(x, 2);  // 'Pow' method from 'Math' class. x raised to power of 2.
            double b = Math.Sqrt(x);  // Square root of x.
            double c = Math.Abs(x);  // Absolute value = how far the value is from 0.
            double d = Math.Round(x);  // Rounds x to nearest int.
            double e = Math.Ceiling(x); // Always rounds up. Alternative to Floor().
            double f = Math.Floor(x);
            double g = Math.Max(e, f);  // Finds max value from arguments. Alternative to Min().
            double h = Math.Min(e, f);

            Console.WriteLine(a);
            Console.WriteLine(b);
            Console.WriteLine(c);
            Console.WriteLine(d);
            Console.WriteLine(e);
            Console.WriteLine(f);
            Console.WriteLine(g);
            Console.WriteLine(h);
        }
    }
}