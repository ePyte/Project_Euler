using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;


namespace P22
{
    internal class NameScore
    {
        private string path;
        private string[] names;
        private int correctionValue = ((int)'A') - 1;


        public NameScore(string path)
        {
            this.path = path;
            ReadInputs();
            char charA = 'A';
            Console.WriteLine("Int value of char A: " + (int)charA);
            char charZ = 'Z';
            Console.WriteLine("Int value of char Z: " + (int)charZ);
        }

        private void ReadInputs()
        {
            try
            {
                CultureInfo enCulture = new CultureInfo("en-EN");//or change Windows' language to ENG

                StreamReader sr = new StreamReader(this.path);

                string line = sr.ReadLine() ?? "";
                names = line.Split(",").Select(name => name.Trim('"')).ToArray();

                Array.Sort(names, StringComparer.Create(enCulture, ignoreCase: false));
                sr.Close();
            }
            catch (FileNotFoundException ex)
            {
                Console.WriteLine(ex.FileName + "File was not found");
            }
            catch (OutOfMemoryException)
            {
                Console.WriteLine("Out of memory.");
            }
        }

        internal int GetFinalValue()
        {
            int sum = 0;
            for (int i = 0; i < names.Length; i++)
            {
                sum += ((i + 1) * GetWordValue(names[i]));
            }
            return sum;
        }

        private int GetWordValue(string word)
        {
            int sumWord = 0;
            for (int i = 0; i < word.Length; ++i)
            {
                sumWord += ((int)word[i]) - correctionValue;
            }
            return sumWord;
        }
    }
}

