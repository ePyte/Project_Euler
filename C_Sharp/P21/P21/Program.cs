namespace P21
{
    internal class Program
    {
        static void Main(string[] args)
        {
            const int end = 10000;
            Amicable nextAm = new Amicable(end);
            Console.WriteLine(nextAm.GetSum());

        }
    }
}
