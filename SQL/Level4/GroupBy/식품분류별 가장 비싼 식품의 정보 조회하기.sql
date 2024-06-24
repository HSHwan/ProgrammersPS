SELECT p2.CATEGORY, p2.MAX_PRICE, PRODUCT_NAME
FROM food_product AS p1
INNER JOIN (SELECT category, MAX(price) AS MAX_PRICE
            FROM food_product
            WHERE category IN ("과자", "국", "김치", "식용유")
            GROUP BY category) AS p2
ON p1.category = p2.category AND p1.price = p2.max_price
GROUP BY category
ORDER BY max_price DESC;