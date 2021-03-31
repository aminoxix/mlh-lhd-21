<?php

namespace App;

use Illuminate\Database\Eloquent\Model;
use GuzzleHttp\Client as GuzClient;
use Twilio\Rest\Client;
use App\Mail\EmailQuote;
use Mail;

class Quote extends Model
{
    /**
     * Fetch quotes from  Forismatic and Favqs APIs
     */
    public function fetchQuotes(){
        // quote from forismatic
        $client = new GuzClient();
        $quote=[];
        $request = $client->get('http://api.forismatic.com/api/1.0/?method=getQuote&format=json&lang=en');
        $data=json_decode($request->getBody()->getContents());
        $quote[0]=$data->quoteText."-".$data->quoteAuthor;
        //quote from Favqs
        $client = new GuzClient();
        $request = $client->get('https://favqs.com/api/qotd');
        $data=json_decode($request->getBody()->getContents());
        $quote[1]=$data->quote->body."-".$data->quote->author;
        return $quote;
    }
    
    /**
    * send Twilio SMS
    *
    * @param $to
    * @param $sms_body
    */
    function sendSMS( $to, $sms_body ) {
    // Your Account SID and Auth Token from twilio.com/console
      $sid    = getenv('TWILIO_SID');
      $token  = getenv('TWILIO_AUTH_TOKEN');
      $client = new Client( $sid, $token );
      $client->messages->create(
         $to,
         array(
            // A Twilio phone number you purchased at twilio.com/console
            'from' => getenv( 'TWILIO_PHONE_NUMBER' ),
            // the body of the text message you'd like to send
            'body' => $sms_body[0]." ".$sms_body[1]
         )
      );
    }

    /**
     * Send email using Sendgrid
     * @param $email_address
     * @param $body
     */
    public function sendEmail($email_address,$body){
        Mail::to($email_address)->send(new EmailQuote($body));
    }

    /**
     * The Quote App
     */
    public function quoteApp(){
        // ideally this should come from database
        $recipients=
        [
            [
            'to' => '07*********',
            'email_address' => 'your email address'
            ]
        ];
        $quote=$this->fetchQuotes();
        foreach($recipients as $recipient){
            // send sms
            $this->sendSMS($recipient['to'],$quote);
            // send email
            $this->sendEmail($recipient['email_address'],$quote);
        }
    }
}
