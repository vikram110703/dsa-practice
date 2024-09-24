select a1.machine_id ,
ROUND(SUM(abs(a2.timestamp-a1.timestamp))/(Count(a1.process_id)),3) as processing_time 
from Activity a1 
left join Activity a2 
on a1.machine_id=a2.machine_id and a1.process_id=a2.process_id and a1.activity_type != a2.activity_type
GROUP by a1.machine_id ;
