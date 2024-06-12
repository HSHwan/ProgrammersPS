SELECT MONTH(start_date) AS MONTH, CAR_ID, COUNT(1) AS RECORDS
FROM car_rental_company_rental_history
WHERE car_id IN (SELECT car_id
                 FROM car_rental_company_rental_history
                 WHERE YEAR(start_date) = 2022 AND MONTH(start_date) BETWEEN 8 AND 10
                 GROUP BY car_id
                 HAVING COUNT(1) >= 5
                ) AND YEAR(start_date) = 2022 AND MONTH(start_date) BETWEEN 8 AND 10
GROUP BY MONTH, car_id
ORDER BY MONTH, car_id DESC;