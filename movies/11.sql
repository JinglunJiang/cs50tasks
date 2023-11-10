select movies.title from movies
join
(select movie_id, rating from ratings
where movie_id in
(select movie_id from stars
where person_id in
(select id from people
where name = 'Chadwick Boseman'))) as table2
on movies.id = table2.movie_id
order by table2.rating desc
limit 5;