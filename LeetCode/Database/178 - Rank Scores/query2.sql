-- ==================================================
-- Problem  :   178 - Rank Scores 
-- Run time :   0.226 sec
-- Language :   SQL
-- ==================================================

SELECT
	Score AS score,
	DENSE_RANK() OVER (ORDER BY SCORE DESC) AS `Rank`
FROM Scores
ORDER BY Score DESC;
