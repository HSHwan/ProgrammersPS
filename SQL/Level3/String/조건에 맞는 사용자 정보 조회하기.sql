SELECT U.USER_ID, U.NICKNAME, CONCAT(U.CITY, " ", STREET_ADDRESS1, " ", STREET_ADDRESS2) AS 전체주소, 
CONCAT(SUBSTR(U.TLNO, 1, 3), "-", SUBSTR(U.TLNO, 4, 4), "-", SUBSTR(U.TLNO, 8, 4)) AS 전화번호
FROM USED_GOODS_BOARD AS B INNER JOIN USED_GOODS_USER AS U ON B.WRITER_ID = U.USER_ID
GROUP BY B.WRITER_ID
HAVING COUNT(B.WRITER_ID) >= 3
ORDER BY U.USER_ID DESC