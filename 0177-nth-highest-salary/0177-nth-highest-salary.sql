CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
DETERMINISTIC
BEGIN
DECLARE offsetValue INT;
SET offsetValue = N-1;
  RETURN (
    SELECT DISTINCT salary
    FROM Employee
    ORDER BY salary DESC
    LIMIT 1 OFFSET offsetValue
  );
END;
