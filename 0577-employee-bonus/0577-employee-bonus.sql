select e.name,b.bonus 
from Employee e 
left join Bonus b
on e.empId = b.empId 
where b.bonus is null  OR b.bonus < 1000 ; 