SELECT e2.ID
FROM (SELECT e1.ID, e2.PARENT_ID
      FROM ecoli_data AS e1
      INNER JOIN ecoli_data AS e2
      ON e1.parent_id = e2.id) AS e2
INNER JOIN ecoli_data AS e3
ON e2.parent_id = e3.id
WHERE ISNULL(e3.parent_id)
ORDER BY e2.ID;