SELECT ID,
CASE
WHEN percentage <= 0.25 THEN "CRITICAL"
WHEN percentage <= 0.5 THEN "HIGH"
WHEN percentage <= 0.75 THEN "MEDIUM"
ELSE "LOW"
END AS COLONY_NAME
FROM (SELECT ID, (RANK() OVER (ORDER BY size_of_colony DESC) / (SELECT COUNT(*)
                                                                FROM ecoli_data)) AS PERCENTAGE 
      FROM ecoli_data) AS e
ORDER BY id;