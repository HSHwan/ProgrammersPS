SELECT r.FOOD_TYPE, REST_ID, REST_NAME, FAVORITES
FROM (SELECT food_type, MAX(favorites) AS max_favorites FROM rest_info GROUP BY food_type) AS max_favor
INNER JOIN rest_info AS r
ON max_favor.food_type = r.food_type AND max_favor.max_favorites = r.favorites
ORDER BY food_type DESC;