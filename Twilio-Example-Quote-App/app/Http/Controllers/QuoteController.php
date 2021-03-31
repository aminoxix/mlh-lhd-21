<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Quote;

class QuoteController extends Controller
{
    public function index(){
        $quote= new Quote();
        dd($quote->fetchQuotes());
    }
}
