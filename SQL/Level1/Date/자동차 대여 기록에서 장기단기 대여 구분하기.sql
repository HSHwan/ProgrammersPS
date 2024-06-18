SELECT HISTORY_ID, 
       CAR_ID,
       DATE_FORMAT(start_date, "%Y-%m-%d") AS START_DATE,
       DATE_FORMAT(end_date, "%Y-%m-%d") AS END_DATE,
       IF(DATEDIFF(end_date, start_date) + 1 >= 30, "장기 대여", "단기 대여") AS RENT_TYPE
FROM car_rental_company_rental_history
WHERE start_date LIKE "2022-09-__"
ORDER BY history_id DESC;