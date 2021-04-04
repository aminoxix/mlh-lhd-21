# React Native linode API client app

If i get enough work on this before 2021 I'll submit it as a Level1Techs "Devember" project.

## Running development version

Development with an android phone works hassle free.

For runnging the web version you'll need https://github.com/Rob--W/cors-anywhere for a local API proxy.
And switch static.js's const settings object to use window.localStorage as storage backend and apiBaseUrl to use the local API proxy.

## TODO:

- Revamp API requests.
^ Has to be done beafore the app gets to big

Utilities for local API cache with pr. API path TTL?
#efficient

app.json
- "./assets/adaptive-icon.png",
