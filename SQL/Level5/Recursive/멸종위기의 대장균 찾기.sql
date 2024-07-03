WITH RECURSIVE ecoli_generations AS (
    SELECT ID, PARENT_ID, 1 AS GENERATION
    FROM ecoli_data
    WHERE parent_id IS NULL
    UNION ALL (
        SELECT e.ID, e.PARENT_ID, eg.GENERATION + 1 AS GENERATION
        FROM ecoli_data AS e
        INNER JOIN ecoli_generations AS eg
        ON e.parent_id = eg.id
    )
)

SELECT COUNT(1) AS COUNT, GENERATION
FROM ecoli_generations
WHERE id NOT IN (SELECT parent_id
                 FROM ecoli_data
                 WHERE parent_id IS NOT NULL)
GROUP BY generation;