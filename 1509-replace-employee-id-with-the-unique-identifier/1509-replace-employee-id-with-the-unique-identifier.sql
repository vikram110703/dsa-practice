# Write your MySQL query statement below
select EU.unique_id,e.name
from Employees as e 
left join EmployeeUNI as EU
on e.id=EU.id ;