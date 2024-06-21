SELECT ID,
CASE
    WHEN size_of_colony <= 100 THEN "LOW"
    WHEN size_of_colony BETWEEN 101 AND 1000 THEN "MEDIUM"
    ELSE "HIGH"
END AS SIZE
FROM ecoli_data
ORDER BY id;