SELECT h.HOUR, IFNULL(o.count, 0) AS COUNT
FROM (VALUES ROW(0), ROW(1), ROW(2), ROW(3), ROW(4), ROW(5),
             ROW(6), ROW(7), ROW(8), ROW(9), ROW(10), ROW(11),
             ROW(12), ROW(13), ROW(14), ROW(15), ROW(16), ROW(17),
             ROW(18), ROW(19), ROW(20), ROW(21), ROW(22), ROW(23)
     ) AS h(HOUR)
LEFT JOIN (SELECT HOUR(datetime) AS HOUR, COUNT(1) AS COUNT
           FROM animal_outs
           GROUP BY HOUR(datetime)) AS o
ON h.hour = o.hour
ORDER BY h.hour;