SELECT p.PRODUCT_ID, PRODUCT_NAME, SUM(amount) * price AS TOTAL_SALES
FROM (SELECT PRODUCT_ID, AMOUNT
      FROM food_order
      WHERE produce_date LIKE "2022-05-__") AS o
INNER JOIN food_product AS p
ON o.product_id = p.product_id
GROUP BY p.product_id
ORDER BY total_sales DESC, p.product_id;