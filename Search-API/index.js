async function go(){
    query = document.getElementById("search").value;
    //console.log(query);
    const response = await fetch(`https://api.duckduckgo.com/?q=${query}&format=json&t=aminos`)
    .then(response => response.json());
    json = response
    console.log(json);
    document.getElementById("word").innerHTML = `<a href="${json.AbstractURL}">${json.AbstractURL}</a>`;
}
