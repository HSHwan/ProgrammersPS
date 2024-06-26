SELECT DATE_FORMAT(SALES_DATE, "%Y-%m-%d") AS SALES_DATE, PRODUCT_ID, USER_ID, SALES_AMOUNT
FROM online_sale
WHERE sales_date LIKE "2022-03-__"
UNION
SELECT DATE_FORMAT(SALES_DATE, "%Y-%m-%d") AS SALES_DATE, PRODUCT_ID, NULL AS USER_ID, SALES_AMOUNT
FROM offline_sale
WHERE sales_date LIKE "2022-03-__"
ORDER BY sales_date, product_id, user_id;