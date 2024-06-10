SELECT animal_type, COUNT(1) AS count
FROM animal_ins
GROUP BY animal_type
HAVING animal_type IN ("Cat", "Dog")
ORDER BY animal_type;