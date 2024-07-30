# Write your MySQL query statement below
select c.contest_id,
ROUND((COUNT(distinct c.user_id)*100)/(select Count(u.user_id) from Users u),2) 
as percentage from Register c
group by c.contest_id
order by percentage desc , contest_id ;
