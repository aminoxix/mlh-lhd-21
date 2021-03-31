using System;

namespace health_app
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Have you cuddled Developer Student Community in the past week?");
            if(Console.ReadLine().ToLower()[0] == 'y'){
                Console.WriteLine("Cheers, Developer Student Community makes you healthy!");
            }
            else{
                Console.WriteLine("Don't go with any other community, you're Xtreme unhealthy!");
            }
        }
    }
}
