SELECT USER_ID, NICKNAME, SUM(price) AS TOTAL_SALES
FROM used_goods_board AS b
INNER JOIN used_goods_user AS u
ON b.writer_id = u.user_id
WHERE b.status = "DONE"
GROUP BY u.user_id, u.nickname
HAVING total_sales >= 700000
ORDER BY total_sales;