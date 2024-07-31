# Write your MySQL query statement below
-- 2019-07-27
SELECT 
    a.activity_date as day,
    COUNT(DISTINCT a.user_id) AS active_users 
FROM 
    activity AS a
WHERE 
    a.activity_date > '2019-06-27'
    AND a.activity_date <= '2019-07-27'
GROUP BY 
    a.activity_date;

