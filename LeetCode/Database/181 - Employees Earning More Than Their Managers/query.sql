-- ==================================================
-- Problem  :   181 - Employees Earning More Than Their Managers
-- Run time :   0.331 sec
-- Language :   SQL
-- ==================================================

SELECT
	e.Name AS Employee
FROM
	Employee AS e
INNER JOIN Employee AS m ON
	e.ManagerId = m.Id
	AND e.Salary > m.Salary;
