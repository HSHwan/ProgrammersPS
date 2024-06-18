SELECT FLAVOR
FROM (SELECT * FROM first_half
      UNION ALL
      SELECT * FROM july) AS all_order
GROUP BY flavor
ORDER BY SUM(total_order) DESC
LIMIT 3;