SELECT o.ANIMAL_ID, ANIMAL_TYPE, NAME
FROM (SELECT ANIMAL_ID, ANIMAL_TYPE, NAME
      FROM animal_outs
      WHERE sex_upon_outcome NOT LIKE "Intact%") AS o
INNER JOIN (SELECT ANIMAL_ID
            FROM animal_ins
            WHERE sex_upon_intake LIKE "Intact%") AS i
ON o.animal_id = i.animal_id
ORDER BY o.animal_id;