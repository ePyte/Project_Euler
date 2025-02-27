using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P21
{
    internal class Amicable
    {
        private int end;
        private int[] numAr;
        public Amicable(int end)
        { 
            this.end = end+1;//indexing starts from 1 not from 0
            this.numAr = new int[this.end];
        }

        public int GetSum()
        {
            numAr[1] = 1;//because of .Remove() in GetDivisorSum
            for (int i = 2;i < this.end; ++i)
            {
                numAr[i] = GetDivisorSum(i);
            }

            int sumOfAmicable = 0;

            for (int i = 1; i < this.end; ++i)
            {
                if (numAr[i] == 1 || numAr[i]>this.end || i == numAr[i])//1 values(primes) are skipped || avioding over indexing || number and the sum of real dividers cannot be the same e.g. 6 -> 1+2+3
                {
                    continue;
                }
                else
                {
                    if(i == numAr[numAr[i]])
                    {
                        sumOfAmicable += numAr[i];
                        sumOfAmicable += numAr[numAr[i]];
                        numAr[numAr[i]] = 1; //to avoid double counting
                    }
                }
            }
            return sumOfAmicable;
        }

        private int GetDivisorSum(int currNum)
        {
            List<int> divisorCollection = new List<int>();
            for(int i = 1;  i <= currNum; ++i)
            {
                if(currNum % i == 0)
                {
                    divisorCollection.Add(i);
                }
            }
            divisorCollection.Remove(currNum);

            return divisorCollection.Sum();
        }
    }
}
