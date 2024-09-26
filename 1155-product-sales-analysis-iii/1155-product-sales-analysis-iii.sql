select s.product_id,s.year as first_year,s.quantity,s.price 
from Sales s
left join Sales ss
on s.product_id = ss.product_id and s.year>ss.year
where ss.year is Null 
-- group by s.product_id ;
