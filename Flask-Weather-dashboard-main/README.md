# Flask Weather Dashboard
#### DAY 1

Build with a Starter Pack (**MLH LHD**)

Today, we'll be learning how to build a weather dashboard with Python & Flask that takes in a zip code, crawls the OpenWeatherMap API and returns the results to the user! This project is particularly special to me because it's the first project I ever built when learning how to code and is a great place to start for anyone who wants to level up their skills.

This is a beginner friendly tutorial! Here's what you'll learn:

- Use the Requests module in Python
- Parse JSON returned by the Weather API
- Render the dashboard and results in Flask

## Part 1: Calling and Parsing the Weather API

Alright! The first thing we have to do is create an account on OpenWeatherMap to get access to their Weather API. Head over to https://openweathermap.org/, click on Sign In and then Create an Account.

Once you've made your account on OpenWeatherMap, the next step is to access your API credentials. In your inbox, you should've received a Welcome email that specifies your API Key, or you can head over to their website and access your API Key underneath the tab API Keys.

The only downside with OpenWeatherMap is that it takes a while for the API Key to get activated. On my end, I had to wait ~20 minutes before the example link provided in the email worked. Feel free to continue with the rest of the tutorial until the API key comes online.

In the OpenWeatherMap API Docs, we can see that they have an API call for getting the current weather of an inputted Zip Code. This is the API call that we'll be using in this project.

Let's head over to an editor of your choice and start building out our service. I'm an avid fan of PyCharm (trust me you won't look back). Go ahead and create a new project, and inside of that create a file called app.py  with the following contents:

```
import requests
import configparser

def get_api_key():
	config = configparser.ConfigParser()
	config.read('config.ini')
    return config['openweathermap']['api']

def get_weather_results(zip_code, api_key):
	 api_url = "https://api.openweathermap.org/data/2.5/weather?zip={}&units=imperial&appid={}".format(zip_code, api_key)
    r = requests.get(api_url)
    return r.json()
    
print(get_weather_results("95129", get_api_key())
```

And then create a configurations file called config.ini that has the following code:

```
[openweathermap]
api=YOUR_API_KEY
```
Here's a quick explanation of the above code. Rather than copying and pasting our API_KEY in multiple places, we created a configuration file called config.ini to hold our OpenWeatherMap API Key, and then used the requests module in Python to call the completed API Url with our zip code and key. Once we have the results, we're returning it in a JSON format for us to easily parse and comprehend the results.

If you run app.py now, you'll see the results of the API call printed out in your console. Let's get this running on a web page now.

## Part 2: Building the Flask Components
The next step is to build out the Dashboard infrastructure, i.e. the Flask website that will take in a zip code as user input, and then take the user to the Dashboard page to view the results.

Let's go ahead and modify our app.py with the addition of the Flask infrastructure:

```
from flask import Flask, render_template, request
import configparser
import requests

app = Flask(__name__)
app.debug = True

@app.route('/')
def weather_dashboard():
    return render_template('home.html')

@app.route('/results', methods=['POST'])
def render_results():
    zip_code = request.form['zipCode']
    
    return "Zip Code: " + zip_code
    
def get_api_key():
	config = configparser.ConfigParser()
	config.read('config.ini')
    return config['openweathermap']['api']

def get_weather_results(zip_code, api_key):
	 api_url = "https://api.openweathermap.org/data/2.5/weather?zip={}&units=imperial&appid={}".format(zip_code, api_key)
    r = requests.get(api_url)
    return r.json()
    
if __name__ == '__main__':
	app.run()
```

We've created a simple Flask app with two routes, one for the home page that will have the input field to enter in a zip code, and then the results page which is routed to /results that will call the API and show the results.

We need to create the template 'home.html' that we're currently rendering, and then pass the form data as a POST request to /results. We haven't made the form yet, but the form will have a zip code input that we can access from the POST request.

In your project, create a new folder called templates and inside of that, create a new file called home.html with the following content:

```
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Weather Dashboard</title>
    <link href="https://fonts.googleapis.com/css2?family=Lato:wght@400;700&display=swap" rel="stylesheet">
    <link rel= "stylesheet" type= "text/css" href= "{{ url_for('static',filename='styles/home.css') }}">
</head>
<body>
<h2>Weather Dashboard in Flask</h2>
<form id="weatherForm" action="{{ url_for('results') }}" method="post">
    Location Zip Code: <input id="weatherInput" type="text" name="zipCode"><br>
    <input id="weatherSubmit" type="submit" value="Submit">
</form>
</body>
</html>
```

And then create a new folder called static, with a sub-folder called styles. Inside of styles create a new file called home.css with the following code:

```
h2 {
    font-family: 'Lato', sans-serif;
    font-size: 24px;
    padding-left: 20px;
}

#weatherForm {
    font-family: 'Lato', sans-serif;
    font-size: 24px;
    padding: 20px;
}

#weatherInput {
    font-family: 'Lato', sans-serif;
    font-size: 24px;
}

#weatherSubmit {
    font-family: 'Lato', sans-serif;
    font-size: 24px;
    color: white;
    background-color: salmon;
    padding: 5px 20px;
    border-radius: 5px;
    margin-top: 20px;
}

#weatherSubmit:hover {
    cursor: pointer;
}
```

Let's do a quick dive into what this code is doing.

Our home.html page consists of a simple h2 tag, and a form that asks the user to input their zip code. We've given the form an action that calls the Jinja2 url_for method, taking the user to the results page of our dashboard which is located at '/results'. The method we've specified is POST, since we're sending the form data to the specified location. The rest of the code is some HTML and CSS beautifications to make the site pretty.

If you run your Flask app now, with the command python3 app.py you should see the following webpage:

Let's do a quick dive into what this code is doing.

Our home.html page consists of a simple h2 tag, and a form that asks the user to input their zip code. We've given the form an action that calls the Jinja2 url_for method, taking the user to the results page of our dashboard which is located at '/results'. The method we've specified is POST, since we're sending the form data to the specified location. The rest of the code is some HTML and CSS beautifications to make the site pretty.

If you run your Flask app now, with the command python3 app.py you should see the following webpage:

Let's do a quick dive into what this code is doing.

Our home.html page consists of a simple h2 tag, and a form that asks the user to input their zip code. We've given the form an action that calls the Jinja2 url_for method, taking the user to the results page of our dashboard which is located at '/results'. The method we've specified is POST, since we're sending the form data to the specified location. The rest of the code is some HTML and CSS beautifications to make the site pretty.

If you run your Flask app now, with the command python3 app.py you should see the following webpage:

<img width="500" alt="image" src="https://user-images.githubusercontent.com/75872316/112799835-81a7a180-908c-11eb-9561-357bcee4d4d3.png">

Entering in your zip code should take you to the /results Page with the output:
- zip code: 95129

## Part 3: Fusing our Front-End and Back-End
The last step for this project is to take the zip code from the POST request, call our API with it and render the results to the user. Go ahead and modify the results route function to look like this:

```
@app.route('/results', methods=['POST'])
def render_results():
    zip_code = request.form['zipCode']

    api_key = get_api_key()
    data = get_weather_results(zip_code, api_key)
    temp = "{0:.2f}".format(data["main"]["temp"])
    feels_like = "{0:.2f}".format(data["main"]["feels_like"])
    weather = data["weather"][0]["main"]
    location = data["name"]

    return render_template('results.html',
                           location=location, temp=temp,
                           feels_like=feels_like, weather=weather)
```
Once we've gotten the zip code, we're simply calling the API method we created in the first part, and then parsing the contents of the call. You can play around with what values are relevant to you, but we're essentially drilling down in the returned JSON and getting various attributes of the data such as weather and location.

After we've parsed and gotten the necessary information, we can pass these values into our render_template method to render our dashboard view of the results.

Let's create the results.html in our templates folder and the respective css file in static/styles like this:

```
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Results Page</title>
    <link rel="stylesheet" type="text/css" href="{{ url_for('static', filename='styles/results.css') }}">
    <link href="https://fonts.googleapis.com/css2?family=Lato:wght@400;700&display=swap" rel="stylesheet">
</head>
<body>
<div id="weatherResults">
    <h3>Weather in {{ location }}</h3>
    <h2>{{ temp }}° F</h2>
    <h3>{{ weather }}</h3>
    <h4>Feels like: {{ feels_like }}° F</h4>
</div>
</body>
</html>
```

```
#weatherResults {
    background-color: #fa8072;
    font-family: 'Lato', sans-serif;
    font-size: 24px;
    padding: 20px;
    display: inline-block;
    text-align: center;
    margin: 20px;
    border-radius: 10px;
}
```

All these two files are doing is nicely rendering the data we are passing in from the render_template method. By using Jinja2 in the HTML template, we can render these values using the curly brackets.

And that's it! If you go ahead and run your app.py file now and enter in the zip code, you should see this dashboard of results:

![500079900223_221246](https://user-images.githubusercontent.com/75872316/112803334-cb928680-9090-11eb-81d0-036475a5824e.jpg)


**THANKS!**
