const user = "aminos";

async function go(){
    if(document.getElementById("user").value == "aminos"){
        console.log("yeet");

        const response = await fetch("https://api.weatherapi.com/v1/current.json?key=c8f3b7097046493a948214424212903&q=IM2&aqi=no")
        .then(response => response.json());
        json = response
        console.log(json.current.temp_c);
        if(json.current.temp_c < 10){
            content.innerHTML += "<br>Too hot to log in.."
        }
        else{
            section.innerHTML = "<h1>Welcome AMINOs!</h1>"
        }

    }
    else{
        console.log("no yeet");
        content = document.getElementById("content");
        content.innerHTML += "<br>Too hot to log in.."
    }
}
