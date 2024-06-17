SELECT COUNT(1) AS FISH_COUNT, MAX(length) AS MAX_LENGTH, FISH_TYPE
FROM (SELECT FISH_TYPE, IFNULL(length, 10) AS length FROM fish_info) AS fish_len
GROUP BY fish_type
HAVING AVG(length) >= 33
ORDER BY fish_type;