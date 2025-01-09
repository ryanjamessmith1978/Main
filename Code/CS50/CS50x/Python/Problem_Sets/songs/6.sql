/*
In 6.sql, write a SQL query that lists the names of songs that are by Post Malone.
Your query should output a table with a single column for the name of each song.
You should not make any assumptions about what Post Malone’s artist_id is.
*/

SELECT name FROM songs WHERE songs.artist_id = (SELECT id FROM artists WHERE name = 'Post Malone');

/* SELECT * FROM songs JOIN artists ON songs.artist_id = artists.id WHERE artists.id = (SELECT id FROM artists WHERE name = 'Post Malone') LIMIT 15;


/* (SELECT id FROM artists WHERE name = 'Post Malone'); */