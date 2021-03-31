<?php

namespace App\Console\Commands;

use Illuminate\Console\Command;
use App\Quote;

class sendQuotes extends Command
{
    /**
     * The name and signature of the console command.
     *
     * @var string
     */
    protected $signature = 'send:quote';

    /**
     * The console command description.
     *
     * @var string
     */
    protected $description = 'send SMS and Email using Twilio and Sendgrid respectively';

    /**
     * Create a new command instance.
     *
     * @return void
     */
    public function __construct()
    {
        parent::__construct();
    }

    /**
     * Execute the console command.
     *
     * @return mixed
     */
    public function handle()
    {
        $quote=new Quote();
        $quote->quoteApp();
        $this->info('Success :)');
    }
}
