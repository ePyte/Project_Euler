using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Runtime.InteropServices.JavaScript.JSType;

namespace P23
{
    internal class NonAbundantSums
    {
        private const int startValue = 12;
        private const int endValue = 28123;
        private const int firstInt = 1;
        private List<int> abundantNumbersList = new List<int>();
        private List<int> evenAbundantNumbersList = new List<int>();
        private List<int> oddAbundantNumbersList = new List<int>();
        private int sumOfIntsUntil = 0; //idea: calculate the sum of ints which can be calculated by adding together 2 abundant numbers, the substract this from this int

        public NonAbundantSums()
        {
            collectAbundantNumbers();

            calculateSumOfIntsUntil();

        }

        private void collectAbundantNumbers()
        {
            for(int i = startValue; i<= endValue; ++i)
            {
                if (isAbundantNumber(i))
                {
                    abundantNumbersList.Add(i);
                }
            }

            foreach (int number in abundantNumbersList)
            {
                if(number % 2 == 0)
                {
                    evenAbundantNumbersList.Add(number);
                }
                else
                {
                    oddAbundantNumbersList.Add(number);
                }
            }
            
        
        }

        private bool isAbundantNumber(int number)
        {
            List<int> divisors = new List<int>();
            for(int i= 1; i<= (int)(number/2); ++i)
            {
                if(number % i == 0)
                {
                    divisors.Add(i);
                }
            }
            return divisors.Sum() > number;
        }

        private void calculateSumOfIntsUntil()
        {
            sumOfIntsUntil = (firstInt + endValue) * endValue / 2;
        }


        public int getResult()
        {
            int sum = 0;
            for(int i = startValue; i <= endValue; ++i)
            {
                Console.WriteLine(i);
                if(i % 2 == 0)
                {
                    sum += evenGetSubResult(i);//even number: sum of 2 evens or sum of 2 odds
                }
                else
                {
                    sum += oddGetSubResult(i);//odd number: sum of 1 even and 1 odd 
                }
            }    
            return sumOfIntsUntil - sum;
        }

        private int evenGetSubResult(int number)
        {
            for (int j = 0; j < evenAbundantNumbersList.Count; ++j)
            {
                if (evenAbundantNumbersList[j] >= number)
                {
                    break;
                }
                for (int k = j; k < evenAbundantNumbersList.Count; ++k)
                {
                    if ((evenAbundantNumbersList[j] + evenAbundantNumbersList[k]) > number)
                    {
                        break;
                    }
                    if (evenAbundantNumbersList[j] + evenAbundantNumbersList[k] == number)
                    {
                        return number;
                    }
                }
            }

            for (int j = 0; j < oddAbundantNumbersList.Count; ++j)
            {
                if (oddAbundantNumbersList[j] >= number)
                {
                    break;
                }
                for (int k = j; k < oddAbundantNumbersList.Count; ++k)
                {
                    if ((oddAbundantNumbersList[j] + oddAbundantNumbersList[k]) > number)
                    {
                        break;
                    }
                    if (oddAbundantNumbersList[j] + oddAbundantNumbersList[k] == number)
                    {
                        return number;
                    }
                }
            }
            return 0;
        }

        private int oddGetSubResult(int number)
        {
            for (int j = 0; j < oddAbundantNumbersList.Count; ++j)
            {

                if (oddAbundantNumbersList[j] >= number)
                {
                    return 0;
                }
                for (int k = 0; k < evenAbundantNumbersList.Count; ++k)
                {
                    if (oddAbundantNumbersList[j] + evenAbundantNumbersList[k] == number)
                    {
                        return number;
                    }
                }
            }
            return 0;
        }
    }
}
