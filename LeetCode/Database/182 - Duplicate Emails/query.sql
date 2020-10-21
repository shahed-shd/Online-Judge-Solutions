-- ==================================================
-- Problem  :   182 - Duplicate Emails
-- Run time :   0.343 sec
-- Language :   SQL
-- ==================================================

SELECT
	Email
FROM
	Person
GROUP BY
	Email
HAVING
	COUNT(Email) > 1;
