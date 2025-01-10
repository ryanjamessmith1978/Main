/*

In 12.sql, write a SQL query to list the titles of all movies in which both Bradley Cooper
and Jennifer Lawrence starred.
Your query should output a table with a single column for the title of each movie.
You may assume that there is only one person in the database with the name Bradley Cooper.
You may assume that there is only one person in the database with the name Jennifer Lawrence.

*/

/*
SELECT title FROM movies
WHERE id IN (SELECT DISTINCT(movie_id) FROM stars
WHERE person_id = (SELECT id FROM people WHERE people.name IN
("Bradley Cooper", "Jennifer Lawrence"))) ORDER BY title;
*/

SELECT title FROM movies JOIN people ON people.id = stars.person_id
JOIN stars ON stars.movie_id = movies.id WHERE people.name = "Bradley Cooper"
INTERSECT
SELECT title FROM movies JOIN people ON people.id = stars.person_id
JOIN stars ON stars.movie_id = movies.id WHERE people.name = "Jennifer Lawrence"
ORDER BY movies.title;