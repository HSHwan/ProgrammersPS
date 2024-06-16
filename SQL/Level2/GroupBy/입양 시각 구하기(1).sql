SELECT HOUR(datetime) AS HOUR, COUNT(1) AS COUNT
FROM animal_outs
GROUP BY HOUR
HAVING hour BETWEEN 9 AND 19
ORDER BY HOUR;