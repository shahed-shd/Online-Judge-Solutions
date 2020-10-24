-- ==================================================
-- Problem  :   177. Nth Highest Salary 
-- Run time :   0.377 sec
-- Language :   SQL
-- ==================================================

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
DETERMINISTIC
BEGIN
	DECLARE OffsetVal INT;
	SET OffsetVal = N - 1;
	RETURN (
		SELECT
			DISTINCT Salary
		FROM
			Employee
		ORDER BY
			Salary DESC
		LIMIT 1 OFFSET OffsetVal
	);
END
