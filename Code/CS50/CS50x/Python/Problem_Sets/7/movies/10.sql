/*

In 10.sql, write a SQL query to list the names of all people who have directed a movie that received
a rating of at least 9.0.
Your query should output a table with a single column for the name of each person.
If a person directed more than one movie that received a rating of at least 9.0,
they should only appear in your results once.

*/

SELECT DISTINCT(name) FROM movies, directors, ratings, people WHERE
movies.id = ratings.movie_id AND ratings.movie_id = directors.movie_id AND
directors.person_id = people.id AND rating >= 9.0;