/*

In 11.sql, write a SQL query to list the titles of the five highest rated movies
(in order) that Chadwick Boseman starred in, starting with the highest rated.
Your query should output a table with a single column for the title of each movie.
You may assume that there is only one person in the database with the name Chadwick Boseman.

*/

SELECT title FROM movies, stars, people, ratings WHERE name = 'Chadwick Boseman'
AND people.id = stars.person_id AND stars.movie_id = movies.id AND movies.id = ratings.movie_id
ORDER BY rating DESC LIMIT 5;