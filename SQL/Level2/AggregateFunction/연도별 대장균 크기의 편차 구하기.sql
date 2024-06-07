SELECT YEAR(differentiation_date) AS year, 
((SELECT MAX(size_of_colony) FROM ecoli_data WHERE YEAR(differentiation_date) = year GROUP BY YEAR(differentiation_date)) - size_of_colony) AS year_dev, id
FROM ecoli_data
ORDER BY year, year_dev;