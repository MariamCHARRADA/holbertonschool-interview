#!/usr/bin/node
const request = require("request");
const movieId = process.argv[2];

if (!movieId || isNaN(movieId) || parseInt(movieId) <= 0) {
  console.error("Error: Please provide a valid positive movie ID.");
  process.exit(1);
}

const url = `https://swapi-api.hbtn.io/api/films/${movieId}`;

request(url, async (error, response, body) => {
  if (error) {
    console.error("Error fetching data:", error);
    process.exit(1);
  }

  if (response.statusCode !== 200) {
    console.error(
      `Error: Unable to fetch movie. Status code: ${response.statusCode}`
    );
    process.exit(1);
  }

  const chars = JSON.parse(body).characters;
  for (const charUrl of chars) {
    await new Promise((resolve) => {
      request(charUrl, (error, response, body) => {
        if (!error && response.statusCode === 200) {
          console.log(JSON.parse(body).name);
        } else {
          console.error(`Error fetching character: ${charUrl}`);
        }
        resolve();
      });
    });
  }
});
