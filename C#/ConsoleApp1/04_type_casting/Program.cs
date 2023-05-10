

namespace type_casting
{
    class Program
    {
        static void Main(string[] args)
        {
            // type casting, converting a value to a different data type.


            // converting double to int.
            double x = 3.14;
            int y = Convert.ToInt32(x);

            // Int to double.
            int z = 123;
            double c = Convert.ToDouble(z) + 0.1;

            // Int to string.
            int f = 100;
            String g = Convert.ToString(f);

            // String to char.
            String h = "A";
            char j = Convert.ToChar(h);

            // String to Boolean.
            String k = "true";
            bool l = Convert.ToBoolean(k);

            Console.WriteLine(y + " " + y.GetType());  //.Gettype() prints datatype of the variable.
            Console.WriteLine(c + " " + c.GetType());
            Console.WriteLine(g + " " + g.GetType());
            Console.WriteLine(j + " " + j.GetType());
            Console.WriteLine(l + " " + l.GetType());
        }
    }
} 