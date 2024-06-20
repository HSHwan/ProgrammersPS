SELECT e.id, COUNT(p.parent_id) AS CHILD_COUNT
FROM ecoli_data AS e
LEFT JOIN ecoli_data AS p
ON e.id = p.parent_id
GROUP BY e.id
ORDER BY e.id;