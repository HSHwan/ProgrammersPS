SELECT COUNT(1) AS FISH_COUNT, MONTH(time) AS MONTH
FROM fish_info
GROUP BY MONTH
ORDER BY MONTH;