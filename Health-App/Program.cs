using System;

namespace health_app
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Have you cuddled a BLAHAJ in the past week?");
            if(Console.ReadLine().ToLower()[0] == 'y'){
                Console.WriteLine("You are being VERY healthy!");
            }
            else{
                Console.WriteLine("You are being EXTREMELY unhealthy!");
            }
        }
    }
}
