-- ==================================================
-- Problem  :   184 - Department Highest Salary
-- Run time :   1.068 sec
-- Language :   SQL
-- ==================================================

SELECT
	d.DepartmentName AS Department,
	e.Name AS Employee,
	d.Maxsalary AS Salary
FROM
	Employee AS e
JOIN (
	SELECT
		e.DepartmentId, d.Name AS DepartmentName, MAX(e.Salary) AS MaxSalary
	FROM
		Employee AS e
	JOIN Department as d ON
		e.DepartmentId = d.Id
	GROUP BY
		e.DepartmentId) AS d ON
	e.DepartmentId = d.DepartmentId
	AND e.Salary = d.MaxSalary;
