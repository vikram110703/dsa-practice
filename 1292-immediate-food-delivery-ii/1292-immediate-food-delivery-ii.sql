# Write your MySQL query statement below

select Round(Avg(if(order_date = customer_pref_delivery_date,1,0))*100,2)
as immediate_percentage  from Delivery
where (customer_id,order_date)
 in (
    select customer_id,min(order_date) as first_order
    from Delivery
    group by customer_id
    );