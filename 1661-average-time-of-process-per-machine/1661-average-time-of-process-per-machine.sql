# Write your MySQL query statement below

select a.machine_id ,ROUND(avg(ABS(a.timestamp-b.timestamp)),3) as processing_time 
from activity a
join activity b on (a.machine_id=b.machine_id and a.process_id=b.process_id and a.activity_type != b.activity_type)
group by machine_id
