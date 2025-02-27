namespace P22
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string path = "0022_names.txt";
            NameScore nameScore = new NameScore(path);
            Console.WriteLine(nameScore.GetFinalValue());

        }
    }
}
