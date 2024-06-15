SELECT hr_avg.DEPT_ID, DEPT_NAME_EN, AVG_SAL
FROM (SELECT dept_id, ROUND(AVG(sal)) AS AVG_SAL
      FROM hr_employees
      GROUP BY dept_id) AS hr_avg
INNER JOIN hr_department AS d
ON hr_avg.dept_id = d.dept_id
ORDER BY avg_sal DESC;