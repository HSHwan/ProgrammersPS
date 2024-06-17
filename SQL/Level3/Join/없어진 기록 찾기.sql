SELECT o.ANIMAL_ID, o.NAME
FROM animal_ins AS i
RIGHT JOIN animal_outs AS o
ON i.animal_id = o.animal_id
WHERE o.animal_id IS NOT NULL AND i.animal_id IS NULL
ORDER BY o.animal_id;