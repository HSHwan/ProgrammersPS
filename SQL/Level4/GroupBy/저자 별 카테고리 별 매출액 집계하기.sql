SELECT AUTHOR_ID, AUTHOR_NAME, CATEGORY, SUM(price * sales) AS TOTAL_SALES
FROM (SELECT BOOK_ID, CATEGORY, PRICE, A.AUTHOR_ID, AUTHOR_NAME
      FROM book AS b
      INNER JOIN author AS a
      ON b.author_id = a.author_id) AS ba
INNER JOIN (SELECT BOOK_ID, SUM(SALES) AS SALES
            FROM book_sales
            WHERE sales_date LIKE "2022-01-__"
            GROUP BY book_id) AS bs
ON ba.book_id = bs.book_id
GROUP BY author_id, category
ORDER BY author_id, category DESC;