using System;
using Twilio;
using Twilio.Rest.Api.V2010.Account;
using Twilio.Types;
using Newtonsoft.Json;
using System.Net.Http;
using System.Threading.Tasks;

namespace TwilioLearn
{
    class Program
    {
        static async Task Main(string[] args)
        {
            var url = "http://quotes.rest/qod.json?category=inspire";

            var client = new HttpClient();
            HttpResponseMessage responseMessage = await client.GetAsync(url);
            var content = await responseMessage.Content.ReadAsStringAsync();
            QuoteModel quote = JsonConvert.DeserializeObject<QuoteModel>(content); 

            var quoteoftheday = quote.contents.quotes[0].quote;

            var accountSid=Secrets.TWILIO_ACCOUNTSID;
            var authToken=Secrets.TWILIO_AUTHTOKEN;
            TwilioClient.Init(accountSid,authToken);

            var to=new PhoneNumber(Secrets.TO_NUMBER);
            //var from=new PhoneNumber(Secrets.FROM_NUMBER);
            //var body = quoteoftheday;

            var message = MessageResource.Create (
                body: quoteoftheday,
                from: new PhoneNumber(Secrets.FROM_NUMBER),
                to: new PhoneNumber(Secrets.TO_NUMBER)
            );

            Console.WriteLine("Message SID = "+message.Sid);
        }
    }
}
