SELECT e.ID, e.GENOTYPE, p.genotype AS PARENT_GENOTYPE
FROM ecoli_data AS e
LEFT JOIN ecoli_data AS p
ON e.parent_id = p.id
WHERE e.genotype = e.genotype | p.genotype
ORDER BY e.id;