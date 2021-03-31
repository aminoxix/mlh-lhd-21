using System;

namespace ExchangeRateCSharp
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            string word = "USD (Dollars)", sign = "$", exchange = "", GBP = "";
            double USD = InputRates(word, sign), EUR = 0, choice = 0;
            while(USD>1.5 || USD < 1.1)
            {
                Console.WriteLine("Invalid rate. Try again");
                USD = InputRates(word, sign);
            }
            word = "EUR (Euros)";
            sign = "E";
            EUR = InputRates(word, sign);
            while (EUR > 1.45 || EUR < 1)
            {
                Console.WriteLine("Invalid rate. Try again");
                EUR = InputRates(word, sign);
            }

            while (true)
            {
                while (exchange != "USD" && exchange != "EUR" && exchange != "EXIT")
                {
                    Console.WriteLine("Enter either:");
                    Console.WriteLine("'USD' for Sterling to Dollar Exchange,");
                    Console.WriteLine("'EUR' for Sterling to Euro Exchange,");
                    Console.WriteLine("Or 'Exit' To quit.");
                    Console.Write(">_");
                    exchange = Console.ReadLine().ToUpper();
                }

                switch (exchange)
                {
                    case "EXIT":
                        Environment.Exit(0);
                        break;
                    case "USD":
                        choice = USD;
                        ExchangeV(exchange, choice);
                        break;
                    case "EUR":
                        choice = EUR;
                        ExchangeV(exchange, choice);
                        break;
                    default:
                        Console.WriteLine("Invalid input. Try again");
                        break;
                }
            }

            

        }
        public static double InputRates(string currency, string sign)
        {
            double value;
            Console.WriteLine($"Enter the exchange rate from GBP (Sterling) to {currency}");
            Console.Write($"£1 -> {sign}");
            value = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine();
            return value;
        }
        public static void ExchangeV(string conversion, double currency)
        {
            string GBP = "";
            double converted;
            while (GBP != "N")
            {
                Console.WriteLine("Use 'N' to exit.");
                Console.WriteLine("Input amount of money in GBP (Sterling):");
                Console.Write(">_");
                GBP = Console.ReadLine().ToUpper();
                if(GBP == "N")
                {
                    Environment.Exit(0);
                }
                if(double.TryParse(GBP, out double GBPNum))
                {
                    converted = GBPNum * currency;
                    Console.WriteLine($"{GBP} in {conversion} is {converted}");

                }
                else
                {
                    Console.WriteLine("Invalid input. Try again");
                }
            }
        }
    }
}
