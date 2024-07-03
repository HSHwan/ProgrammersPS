SELECT e.EMP_NO, EMP_NAME, GRADE,
ROUND(
CASE GRADE
WHEN "S" THEN sal * 0.2
WHEN "A" THEN sal * 0.15
WHEN "B" THEN sal * 0.1
ELSE 0
END) AS BONUS
FROM (SELECT EMP_NO,
      CASE
      WHEN AVG(score) >= 96 THEN "S"
      WHEN AVG(score) >= 90 THEN "A"
      WHEN AVG(score) >= 80 THEN "B"
      ELSE "C"
      END AS GRADE
      FROM hr_grade
      GROUP BY EMP_NO) AS g
INNER JOIN hr_employees AS e
ON g.emp_no = e.emp_no
ORDER BY e.emp_no;