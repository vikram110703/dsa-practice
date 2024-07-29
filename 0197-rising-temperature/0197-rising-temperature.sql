# Write your MySQL query statement below

SELECT a.id from Weather as a
left join Weather as b
on DATEDIFF(a.recordDate,b.recordDate)=1
where a.temperature>b.temperature