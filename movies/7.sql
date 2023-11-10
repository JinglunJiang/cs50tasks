select movies.title, table2.rating
from movies
join
(select movie_id, rating from ratings) as table2
on movies.id = table2.movie_id
where movies.year = '2010'
order by table2.rating desc, movies.title;