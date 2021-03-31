<?php

namespace App\Mail;

use Illuminate\Bus\Queueable;
use Illuminate\Mail\Mailable;
use Illuminate\Queue\SerializesModels;
use Illuminate\Contracts\Queue\ShouldQueue;

class EmailQuote extends Mailable
{
    use Queueable, SerializesModels;

    protected $email_body;

    /**
     * Create a new message instance.
     *
     * @return void
     */
    public function __construct($email_body)
    {
        $this->email_body=$email_body;
    }

    /**
     * Build the message.
     *
     * @return $this
     */
    public function build()
    {
        $data=implode("</br>",$this->email_body);
        return $this->view('emails.quote')->with(['email_body'=>$data]);;
    }
}
