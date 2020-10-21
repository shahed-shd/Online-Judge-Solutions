-- ==================================================
-- Problem  :   175 - Combine Two Tables
-- Run time :   0.317 sec
-- Language :   SQL
-- ==================================================

SELECT
  p.FirstName,
  p.LastName,
  a.City,
  a.State
FROM
  Person as p
  LEFT JOIN Address as a ON p.PersonId = a.PersonId;
