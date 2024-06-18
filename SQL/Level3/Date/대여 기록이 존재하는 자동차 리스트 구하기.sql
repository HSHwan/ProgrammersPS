SELECT DISTINCT c.car_id
FROM car_rental_company_car AS c
INNER JOIN car_rental_company_rental_history AS h
ON c.car_id = h.car_id
WHERE car_type = "세단" AND MONTH(start_date) = 10
ORDER BY c.car_id DESC;