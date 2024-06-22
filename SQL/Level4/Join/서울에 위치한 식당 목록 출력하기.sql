SELECT i.REST_ID, REST_NAME, FOOD_TYPE, FAVORITES, ADDRESS, SCORE
FROM rest_info AS i
INNER JOIN (SELECT rest_id, ROUND(AVG(review_score), 2) AS SCORE
            FROM rest_review
            GROUP BY rest_id) AS r
ON i.rest_id = r.rest_id
WHERE address LIKE "서울%"
ORDER BY score DESC, favorites DESC;