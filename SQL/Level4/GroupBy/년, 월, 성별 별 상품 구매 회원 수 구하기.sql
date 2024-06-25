SELECT YEAR, MONTH, GENDER, COUNT(1) AS USERS
FROM user_info AS u
INNER JOIN (SELECT DISTINCT USER_ID, YEAR(sales_date) AS YEAR, MONTH(sales_date) AS MONTH
            FROM online_sale) AS os
ON u.user_id = os.user_id
WHERE gender IS NOT NULL
GROUP BY year, month, gender
ORDER BY year, month, gender;