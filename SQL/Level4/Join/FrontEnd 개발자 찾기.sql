SELECT DISTINCT ID, EMAIL, FIRST_NAME, LAST_NAME 
FROM developers AS d
LEFT JOIN skillcodes AS s
ON s.code & d.skill_code != 0
WHERE category = "Front End"
ORDER BY id;