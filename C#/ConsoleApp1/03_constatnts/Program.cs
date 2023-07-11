

namespace Constants
{
    class Program
    {
        static void Main(string[] args)
        {
            /* constants =  immutable values which are known at compile time
                            and do not change for the life of the program. */


            double pie = 3.14159;
            pie = 123;

            Console.WriteLine(pie);

            const double pi = 3.14159;  // const makes a variable a constant.
            
            //pi = pi * pi;  // Does not work.

            Console.WriteLine(pi);


        }
    }
}