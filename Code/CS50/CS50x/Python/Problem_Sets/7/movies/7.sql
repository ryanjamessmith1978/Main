/*

In 7.sql, write a SQL query to list all movies released in 2010 and their ratings,
in descending order by rating. For movies with the same rating, order them alphabetically by title.
Your query should output a table with two columns, one for the title of each movie
and one for the rating of each movie. Movies that do not have ratings should not be included in the result.

*/

SELECT rating, title FROM ratings,movies
WHERE ratings.rating != 0.0 AND ratings.movie_id = movies.id AND movies.year = 2010
ORDER BY ratings.rating DESC, movies.title LIMIT 20;