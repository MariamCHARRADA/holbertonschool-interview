#!/usr/bin/node
const request = require("request");

const movieId = process.argv[2];
const url = `https://swapi-api.hbtn.io/api/films/${movieId}`;

request(url, (error, response, body) => {
  if (!error && response.statusCode === 200) {
    const chars = JSON.parse(body).characters;

    const fetchCharacter = (url) => {
      return new Promise((resolve) => {
        request(url, (error, response, body) => {
          if (!error && response.statusCode === 200) {
            console.log(JSON.parse(body).name);
          }
          resolve();
        });
      });
    };

    (async () => {
      for (const charUrl of chars) {
        await fetchCharacter(charUrl);
      }
    })();
  } else {
    console.error("Error fetching movie data:", error || response.statusCode);
  }
});
