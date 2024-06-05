# Write your MySQL query statement below
select P.product_name, S.year,S.price from Sales S left join Product P ON P.product_id=S.product_id;
