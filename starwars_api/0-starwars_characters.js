#!/usr/bin/node
const request = require("request");
const movieId = process.argv[2];
const url = `https://swapi-api.hbtn.io/api/films/${movieId}`;

request(url, (error, response, body) => {
  if (error || response.statusCode !== 200) {
    console.error("Error:", error || `Status code: ${response.statusCode}`);
    return;
  }

  const characters = JSON.parse(body).characters;

  const fetchCharacter = (url) =>
    new Promise((resolve) => {
      request(url, (error, response, body) => {
        if (!error && response.statusCode === 200) {
          console.log(JSON.parse(body).name);
        }
        resolve();
      });
    });

  (async () => {
    for (const charUrl of characters) {
      await fetchCharacter(charUrl);
    }
  })();
});
