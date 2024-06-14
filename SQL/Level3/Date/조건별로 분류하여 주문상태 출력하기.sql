SELECT ORDER_ID, PRODUCT_ID, DATE_FORMAT(out_date, "%Y-%m-%d") AS OUT_DATE,
CASE
    WHEN out_date IS NULL THEN "출고미정"
    WHEN DATEDIFF("2022-05-01", out_date) >= 0 THEN "출고완료"
    ELSE "출고대기"
END AS 출고여부
FROM food_order
ORDER BY order_id;