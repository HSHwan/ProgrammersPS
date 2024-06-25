SELECT HISTORY_ID, ROUND(daily_fee * duration * (100 - IFNULL(discount_rate, 0)) / 100) AS FEE
FROM (SELECT HISTORY_ID, (DATEDIFF(end_date, start_date) + 1) AS DURATION, DAILY_FEE
      FROM car_rental_company_rental_history AS h
      INNER JOIN car_rental_company_car AS c
      ON h.car_id = c.car_id
      WHERE car_type = "트럭") AS ch
LEFT JOIN car_rental_company_discount_plan AS p
ON p.car_type = "트럭" AND p.duration_type = (
    CASE
    WHEN ch.duration >= 90 THEN "90일 이상"
    WHEN ch.duration >= 30 THEN "30일 이상"
    WHEN ch.duration >= 7 THEN "7일 이상"
    ELSE ""
    END
)
ORDER BY fee DESC, history_id DESC;