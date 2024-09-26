-- select s.product_id,s.year as first_year,s.quantity,s.price 
-- from Sales s
-- left join Sales ss
-- on s.product_id = ss.product_id and s.year>ss.year
-- where ss.year is Null 


# Write your MySQL query statement below

WITH CTE AS (
    SELECT product_id, MIN(year) AS minyear FROM Sales 
    GROUP BY product_id 
)

SELECT s.product_id, s.year AS first_year, s.quantity, s.price 
FROM Sales s
INNER JOIN CTE ON cte.product_id = s.product_id  AND s.year = cte.minyear; 