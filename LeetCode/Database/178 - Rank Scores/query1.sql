-- ==================================================
-- Problem  :   178 - Rank Scores 
-- Run time :   0.214 sec
-- Language :   SQL
-- ==================================================

WITH sq AS (
SELECT
	Score,
	ROW_NUMBER() OVER (ORDER BY Score DESC) AS ScoreRank
FROM
	Scores
GROUP BY
	Score)
SELECT
	s.Score AS score,
	sq.ScoreRank AS `Rank`
FROM
	Scores AS s
LEFT JOIN sq ON
	s.Score = sq.Score
ORDER BY
	s.Score DESC;
