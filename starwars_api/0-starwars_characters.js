#!/usr/bin/node

const request = require("request");

const movieId = process.argv[2];
const url = `https://swapi-api.hbtn.io/api/films/${movieId}`;

request(url, async (error, response, body) => {
  if (error || response.statusCode !== 200) {
    console.error("Error fetching movie data:", error || response.statusCode);
    return;
  }

  const characters = JSON.parse(body).characters;

  for (const characterUrl of characters) {
    await new Promise((resolve, reject) => {
      request(characterUrl, (error, response, body) => {
        if (error || response.statusCode !== 200) {
          console.error(
            "Error fetching character data:",
            error || response.statusCode
          );
          resolve();
          return;
        }

        console.log(JSON.parse(body).name);
        resolve();
      });
    });
  }
});
