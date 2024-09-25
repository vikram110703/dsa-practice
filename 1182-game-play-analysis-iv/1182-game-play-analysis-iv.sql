# Write your MySQL query statement below

select Round(Count(distinct player_id )/(select Count(distinct player_id)from Activity),2) as fraction
from Activity a
where (a.player_id, (a.event_date - INTERVAL 1 DAY))
In
(select player_id, min(event_date)as first_login from Activity
  group by player_id
)

