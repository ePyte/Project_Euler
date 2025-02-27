/*
 * Permutation without repetition: 10 digits (0, 1, 2 ... 9)
 * The 1 000 000th string is needed in alphabetical order.
 * There are 9!(= 362 880) strings where the starting digit is 0.
 * There are 362 880 strings starting with digit 1.
 * We need the (1 000 000 - 2 * 362 880 =) 274 240th string starting with 2.
 * If we consider the 2nd digit also, we can further narrow down the iteration.
 * 20..., 21..., 23... each subgroup has 8! = 40 320 elements.
 * 274 240 / 40 320 ~ 6,8 (0, 1, 3, 4, 5, 6 -> 6 digits)
 * 274 240 mod 40 320 = 32 320
 * The string has to start with 27... and we need the 32320th element.
 */

namespace P24
{
    internal class Program
    {
        static int factorial(int x)
        {
            if (x == 0)
            {
                return 1;
            }
            int result = 1;
            for(int i = 1; i <= x; i++)
            {
                result *= i;
            }
            return result;
        }

        static void Main(string[] args)
        {
            string digitsString = "0123456789";
            List<char> digits = new List<char>(digitsString);
            int endInt = 1000000-1;//list is indexed from 0//if only 1 digit is in the list 1/factorial(1) = 1 -> error index: should be 0

            int currentLen = digits.Count-1;//going unti >=0
            String solution = "";

            while(currentLen >= 0)
            {

                int div = endInt / factorial(currentLen);
                int mod = endInt % factorial(currentLen);
                solution += digits[div];
                digits.Remove(digits[div]);
                endInt = mod;

                currentLen--;
            }

            Console.WriteLine(solution);
        }
    }
}
