SELECT YEAR, MONTH,
COUNT(1) AS PURCHASED_USERS,
ROUND(COUNT(1) / (SELECT COUNT(*)
                  FROM user_info
                  WHERE YEAR(joined) = 2021), 1) AS PUCHASED_RATIO
FROM (SELECT USER_ID
      FROM user_info
      WHERE YEAR(joined) = 2021) AS u
INNER JOIN (SELECT USER_ID, YEAR(sales_date) AS YEAR, MONTH(sales_date) AS MONTH
            FROM online_sale
            GROUP BY USER_ID, YEAR(sales_date), MONTH(sales_date)) AS os
ON u.user_id = os.user_id
GROUP BY year, month
ORDER BY year, month;