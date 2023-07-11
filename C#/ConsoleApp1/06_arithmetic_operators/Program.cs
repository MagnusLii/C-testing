

namespace arithmeic_operators
{
    class Program
    {
        static void Main(string[] args)
        {
            int friends = 10;

            // Basic addition.
            friends = friends + 1;
            Console.WriteLine(friends);
            friends += 1;
            Console.WriteLine(friends);
            friends++;  // This format always increases the number by 1, useful in loops.
            Console.WriteLine(friends);

            // Basic subtraction
            friends = friends - 1;
            Console.WriteLine(friends);
            friends -= 1;
            Console.WriteLine(friends);
            friends--;
            Console.WriteLine(friends);

            // Multiplication.
            friends = friends * 2;
            Console.WriteLine(friends);
            friends *= 2;
            Console.WriteLine(friends);

            // Subtraction
            friends = friends / 3;  // Decimal portion will be trunkated cause the var is an int.
            Console.WriteLine(friends);
            friends /= 3;
            Console.WriteLine(friends);

            // Modulos
            int remainder = friends % 3;  // Divides the value of 'friends' into groups of 3 and stores the leftover value once it can no longer be divided into groups of 3.
                                          // As friends is 4 one group of 3 is removed and the since 1 < 3 the remainder is 2.
            Console.WriteLine(remainder);
        }
    }
}