SELECT CATEGORY, SUM(sales) AS TOTAL_SALES
FROM book AS b INNER JOIN book_sales AS bs
ON b.book_id = bs.book_id
WHERE sales_date LIKE "2022-01-__"
GROUP BY category
ORDER BY category;