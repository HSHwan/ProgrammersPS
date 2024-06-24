SELECT cd.CAR_ID, CAR_TYPE, ROUND(daily_fee * (100 - discount_rate) * 0.3) AS FEE
FROM (SELECT CAR_ID, c.CAR_TYPE, DAILY_FEE, DISCOUNT_RATE
      FROM car_rental_company_car AS c
      INNER JOIN (SELECT CAR_TYPE, DISCOUNT_RATE
                  FROM car_rental_company_discount_plan
                  WHERE CAR_TYPE IN ("세단", "SUV") AND duration_type = "30일 이상") AS d
      ON c.car_type = d.car_type
      WHERE ROUND(daily_fee * (100 - discount_rate) * 0.3) BETWEEN 500000 AND 1999999
      ) AS cd
WHERE car_id NOT IN (SELECT DISTINCT car_id
                     FROM car_rental_company_rental_history
                     WHERE ("2022-11-01" BETWEEN start_date AND end_date) OR ("2022-11-30" BETWEEN start_date AND end_date))
ORDER BY fee DESC, car_type, cd.car_id DESC;