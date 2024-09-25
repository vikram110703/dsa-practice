# Write your MySQL query statement below

-- select * from Signups s
SELECT s.user_id,
Round(COUNT(CASE WHEN c.action = 'confirmed' THEN 1 ELSE NULL END)/(Count(s.user_id)),2) AS confirmation_rate
FROM Signups s
LEFT JOIN Confirmations c ON s.user_id = c.user_id
GROUP BY s.user_id;
