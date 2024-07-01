SELECT
CASE
WHEN skill_code & (SELECT SUM(code)
                    FROM skillcodes
                    WHERE category = "Front End")
AND skill_code & (SELECT code
                  FROM skillcodes
                  WHERE name = "Python") THEN "A"
WHEN skill_code & (SELECT code
                   FROM skillcodes
                   WHERE name = "C#") THEN "B"
ELSE "C"
END AS GRADE, ID, EMAIL
FROM developers
WHERE skill_code & (SELECT SUM(code)
                    FROM skillcodes
                    WHERE category = "Front End"
                    GROUP BY category)
OR skill_code & (SELECT code
                 FROM skillcodes
                 WHERE name = "C#")
ORDER BY grade, id;