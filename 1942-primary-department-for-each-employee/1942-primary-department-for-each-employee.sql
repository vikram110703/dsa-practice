SELECT 
    e.employee_id, 
    e.department_id 
FROM 
    Employee e
WHERE 
    e.primary_flag = 'Y'
    OR e.employee_id IN (
        SELECT 
            b.employee_id 
        FROM 
            Employee b
        GROUP BY 
            b.employee_id
        HAVING 
            COUNT(b.department_id) = 1
    );
