SELECT COUNT(1) AS COUNT
FROM ecoli_data
WHERE genotype & 2 = 0 AND genotype & 5 != 0;