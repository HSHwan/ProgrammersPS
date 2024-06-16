SELECT SCORE, e.EMP_NO, EMP_NAME, POSITION, EMAIL
FROM (SELECT emp_no, year, SUM(score) AS score
      FROM hr_grade
      GROUP BY emp_no, year) AS g
INNER JOIN hr_employees AS e
ON g.emp_no = e.emp_no
WHERE score = (SELECT MAX(score) FROM (SELECT SUM(score) AS score
                                       FROM hr_grade
                                       GROUP BY emp_no, year) AS s);