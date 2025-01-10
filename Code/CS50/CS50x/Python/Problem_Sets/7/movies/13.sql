/*

In 13.sql, write a SQL query to list the names of all people who starred in a movie in which
Kevin Bacon also starred.
Your query should output a table with a single column for the name of each person.
There may be multiple people named Kevin Bacon in the database. Be sure to only select the
Kevin Bacon born in 1958.
Kevin Bacon himself should not be included in the resulting list.
*/

/*
83833 - first KB movie ID
SELECT MIN(movies.id) FROM movies, stars, people
WHERE movies.id = stars.movie_id AND stars.person_id = people.id
AND people.id = (SELECT MIN(id) FROM people WHERE name = 'Kevin Bacon');

SELECT name FROM people, stars, movies
WHERE movies.id = 83833 AND people.id = stars.person_id AND stars.movie_id = movies.id
ORDER BY name;*/

SELECT DISTINCT(name) FROM people, movies, stars
WHERE movies.id IN (SELECT movies.id FROM movies, stars, people
WHERE people.id = (SELECT MIN(id) FROM people WHERE name = 'Kevin Bacon')
AND movies.id = stars.movie_id AND stars.person_id = people.id)
AND people.name IS NOT 'Kevin Bacon'
AND people.id = stars.person_id
AND stars.movie_id = movies.id ORDER BY name;