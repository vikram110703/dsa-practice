# Write your MySQL query statement below
select c.class 
FROM Courses as c
group by c.class
HAVING count(c.student)>=5