SELECT CAR_ID, "대여중"
FROM car_rental_company_rental_history
WHERE "2022-10-16" BETWEEN start_date AND end_date
UNION DISTINCT
SELECT CAR_ID, "대여 가능"
FROM car_rental_company_rental_history
WHERE car_id NOT IN (SELECT car_id 
                     FROM car_rental_company_rental_history
                     WHERE "2022-10-16" BETWEEN start_date AND end_date)
ORDER BY car_id DESC;