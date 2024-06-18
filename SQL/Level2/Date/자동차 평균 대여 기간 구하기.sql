SELECT CAR_ID, ROUND(AVG(duration), 1) AS AVERAGE_DURATION
FROM (SELECT CAR_ID, (DATEDIFF(end_date, start_date) + 1) AS duration
      FROM car_rental_company_rental_history) AS car_date
GROUP BY car_id
HAVING AVG(duration) >= 7
ORDER BY average_duration DESC, car_id DESC;