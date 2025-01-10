/*
In 6.sql, write a SQL query to determine the average rating of all movies released in 2012.
Your query should output a table with a single column and a single row (not counting the header)
containing the average rating.
*/
/*
SELECT AVG(rating) FROM ratings,movies WHERE ratings.movie_id = movies.id AND movies.year = 2012;

EXECUTING Query, too many statements at once.  In (SELECT ) does't work either.
NEED to use JOIN
*/

SELECT AVG(rating) FROM ratings
JOIN movies on ratings.movie_id = movies.id
WHERE movies.year = 2012;

/*
SELECT title FROM people
JOIN stars ON people.id = stars.person_id
JOIN shows ON stars.show_id = shows.id
WHERE name = 'Steve Carell';
*/