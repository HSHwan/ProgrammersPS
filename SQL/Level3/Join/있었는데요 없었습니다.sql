SELECT o.ANIMAL_ID, o.NAME
FROM animal_ins AS i
INNER JOIN animal_outs AS o
ON i.animal_id = o.animal_id
WHERE TIMESTAMPDIFF(SECOND, i.datetime, o.datetime) < 0
ORDER BY i.datetime;