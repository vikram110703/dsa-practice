# Write your MySQL query statement below
select  MAX(a.num) as num
FROM
(select b.num from myNumbers b
    group by b.num 
    having count(b.num)=1
) as a
