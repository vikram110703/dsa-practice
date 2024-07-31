# Write your MySQL query statement below
select f.user_id,count(distinct f.follower_id) as followers_count
from Followers f
group by f.user_id